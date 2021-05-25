/*
 * Title: Binary Search Trees
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 2
 * Description: BST
 */
#include "BinaryNode.h"
#include "TreeException.h"
#include <iostream>
using namespace std;
#ifndef HW2_BINARYSEARCHTREE_H
#define HW2_BINARYSEARCHTREE_H


class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& tree);
    ~BinarySearchTree();
    bool isEmpty() const;
    int getHeight() ;
    int getNumberOfNodes()const;
    bool add(const int newEntry);
    bool remove(const int anEntry);
    bool contains(const int anEntry);
    void preorderTraverse();
    void inorderTraverse();
    void postorderTraverse();
    void levelorderTraverse();
    int span(const int a, const int b);
    void mirror();
private:
    BinaryNode *root ;
    int count;
    void copyTree(BinaryNode *treePtr, BinaryNode* & newTreePtr) const;
    void destroyTree(BinaryNode * &treePtr);
    void retrieveItem(BinaryNode * treePtr, int searchKey, int& item);
    void insertItem(BinaryNode * &treePtr,const int& item)throw(TreeException);
    void deleteItem(BinaryNode * &treePtr, int searchKey)throw(TreeException);
    void deleteNodeItem(BinaryNode * &nodePtr);
    void processLeftmost(BinaryNode * &nodePtr, int& item);
    void inorder(BinaryNode *treePtr);
    void postorder(BinaryNode *treePtr);
    void preorder(BinaryNode *treePtr);
    void search(BinaryNode *& treePtr, const int& anEntry, bool & contains);
    int recursiveHeight(BinaryNode *& treePtr);
    int max(int a,int b);
    void helperLevelTraverse(BinaryNode *& treePtr, int i);
    void helperSpan(const int a, const int b, BinaryNode *&treePtr,int &count);
    void mirrorHelper(BinaryNode *&treePtr);
};




#endif //HW2_BINARYSEARCHTREE_H
