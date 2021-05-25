/*
 * Title: Binary Search Trees
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 2
 * Description: BST
 */
#include "BinarySearchTree.h"
#include "TreeException.h"

BinarySearchTree::BinarySearchTree():root(NULL),count(0){}
BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree) {
    copyTree(tree.root, root);
}
void BinarySearchTree::copyTree(BinaryNode *treePtr, BinaryNode *& newTreePtr) const {

    if (treePtr != NULL) {		// copy node
        newTreePtr = new BinaryNode(treePtr->item, NULL, NULL);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
    else
        newTreePtr = NULL;	// copy empty tree
}
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}
void BinarySearchTree::destroyTree(BinaryNode *& treePtr) {

    if (treePtr != NULL){
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}
bool BinarySearchTree::add(const int newEntry) {
    count++;
    insertItem(root, newEntry);
    return true;
}
void BinarySearchTree::insertItem(BinaryNode *& treePtr, const int& newItem) throw(TreeException) {

    // Position of insertion found; insert after leaf
    if (treePtr == NULL) {
        treePtr = new BinaryNode(newItem, NULL, NULL);
        if (treePtr == NULL)
            throw TreeException("TreeException: insert failed");
    }
        // Else search for the insertion position
    else if (newItem < treePtr->item)
        insertItem(treePtr->leftChildPtr, newItem);
    else
        insertItem(treePtr->rightChildPtr, newItem);
}
bool BinarySearchTree::remove(const int anEntry) {
    if(root == NULL)
        return false;
    count--;
    deleteItem(root, anEntry);
    return true;
}
void BinarySearchTree::deleteItem(BinaryNode * &treePtr, int searchKey) throw(TreeException) {
    if (treePtr == NULL) // Empty tree
        throw TreeException("Delete failed");

        // Position of deletion found
    else if (searchKey == treePtr->item)
        deleteNodeItem(treePtr);

        // Else search for the deletion position
    else if (searchKey < treePtr->item)
        deleteItem(treePtr->leftChildPtr, searchKey);
    else
        deleteItem(treePtr->rightChildPtr, searchKey);
}
int BinarySearchTree::getNumberOfNodes() const {
    return count;
}
void BinarySearchTree::preorderTraverse() {
    preorder(root);
}
void BinarySearchTree::inorderTraverse() {
    inorder(root);
}
void BinarySearchTree::postorderTraverse() {
    postorder(root);
}
void BinarySearchTree::preorder(BinaryNode *treePtr) {
    if (treePtr != NULL) {
        cout << treePtr->item;
        preorder(treePtr->leftChildPtr);
        preorder(treePtr->rightChildPtr);
    }
}
void BinarySearchTree::inorder(BinaryNode *treePtr) {
    if (treePtr != NULL) {
        inorder(treePtr->leftChildPtr);
        cout << treePtr->item ;
        inorder(treePtr->rightChildPtr);
    }
}
void BinarySearchTree::postorder(BinaryNode *treePtr) {
    if (treePtr != NULL) {
        postorder(treePtr->leftChildPtr);
        postorder(treePtr->rightChildPtr);
        cout << treePtr->item;
    }
}
bool BinarySearchTree::contains(const int anEntry) {
    bool contains  = false;
    search(root,anEntry,contains);
    return contains;
}
void BinarySearchTree::deleteNodeItem(BinaryNode * &nodePtr) {
    BinaryNode *delPtr;
    int replacementItem;


    // (1)  Test for a leaf
    if ( (nodePtr->leftChildPtr == NULL) &&
         (nodePtr->rightChildPtr == NULL) ) {
        delete nodePtr;
        nodePtr = NULL;
    }


        // (2)  Test for no left child
    else if (nodePtr->leftChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }

        // (3)  Test for no right child
    else if (nodePtr->rightChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }


        // (4)  There are two children:
        //      Retrieve and delete the inorder successor
    else {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }

}
void BinarySearchTree::processLeftmost(BinaryNode *&nodePtr,
                                       int& treeItem){

    if (nodePtr->leftChildPtr == NULL) {
        treeItem = nodePtr->item;
        BinaryNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr, treeItem);
}
void BinarySearchTree::search(BinaryNode *&treePtr, const int &anEntry, bool & contains) {
    if( treePtr == NULL){
        contains = false;
    }
   else if(treePtr->item == anEntry){
        contains = true;
    }
    else if (anEntry < treePtr->item)
        search (treePtr->leftChildPtr,anEntry,contains);
    else if ( anEntry > treePtr->item)
        search (treePtr->rightChildPtr,anEntry,contains);

}
int BinarySearchTree::getHeight()  {
    if(root == NULL)
        return 0;
    return  recursiveHeight(root);
}
int BinarySearchTree::recursiveHeight(BinaryNode *&treePtr) {
    int max;
    if(treePtr == NULL)
        return 0;
    int a = recursiveHeight(treePtr->leftChildPtr);
    int b = recursiveHeight(treePtr->rightChildPtr);
    if ( a >= b)
        max = a;
    else
        max = b;
    return max+1;
}

void BinarySearchTree::levelorderTraverse() {
    // if empty go out
    if( root == NULL)
        return;
    for ( int i = 0; i < getHeight()+1; i++){
        helperLevelTraverse(root,i);
        cout << endl;
    }
}
void BinarySearchTree::helperLevelTraverse(BinaryNode *&treePtr, int i) {
    // stop whether the given pointer null
    if( treePtr == NULL)
        return;
    else if( i == 1)
        cout << treePtr->item  << " ";
    else if( i > 1 ){
        helperLevelTraverse( treePtr->leftChildPtr, i-1);
        helperLevelTraverse( treePtr->rightChildPtr, i-1);
    }
}
int BinarySearchTree::span(const int a, const int b) {
    if(root == NULL)
        return 0;
    int count = 0;
    helperSpan(a,b,root,count);
    return count;
}
void BinarySearchTree::helperSpan(const int a, const int b,BinaryNode *&treePtr, int &count ) {
    if( treePtr == NULL)
        return;
    if (a <= treePtr->item && b >= treePtr->item) {
        count++;
        helperSpan(a, b, treePtr->leftChildPtr, count);
        helperSpan(a, b, treePtr->rightChildPtr, count);
    }
    else if( a > treePtr->item)
        helperSpan(a,b,treePtr->rightChildPtr,count);
    else if( b < treePtr->item)
        helperSpan(a,b,treePtr->leftChildPtr,count);
}
void BinarySearchTree::mirror() {
    if( root == NULL)
        return;
    mirrorHelper(root);
}
void BinarySearchTree::mirrorHelper(BinaryNode *&treePtr) {
    if( treePtr == NULL)
        return;
    mirrorHelper(treePtr->rightChildPtr);
    mirrorHelper(treePtr->leftChildPtr);
    BinaryNode *temp = treePtr->rightChildPtr;
    treePtr->rightChildPtr = treePtr->leftChildPtr;
    treePtr->leftChildPtr = temp;


}