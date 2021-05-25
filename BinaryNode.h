/*
 * Title: Binary Search Trees
 * Author: Alperen Alkan
 * ID: 21803216
 * Section: 3
 * Assignment: 2
 * Description: BinaryNode
 */
#ifndef HW2_BINARYNODE_H
#define HW2_BINARYNODE_H
#include <iostream>

class BinaryNode {
public:
    int getItem();
    void setItem( int a);

private:
    BinaryNode(){}
    BinaryNode(const int& nodeItem, BinaryNode *left = NULL, BinaryNode *right = NULL)
            :item(nodeItem),leftChildPtr(left),rightChildPtr(right) {}
    int item;       // data portion
    BinaryNode *leftChildPtr;  // pointer to left child
    BinaryNode *rightChildPtr; // pointer to right child

    friend class BinarySearchTree;
};





#endif //HW2_BINARYNODE_H
