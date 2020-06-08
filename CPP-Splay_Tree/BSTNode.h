#ifndef BSTNode_h
#define BSTNode_h

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cctype>
#include <sstream>

using namespace std;

/*
 *
 *
 * BSTNode class declaration
 */
class BSTNode {
private:
    BSTNode* leftChild; //stores the left child
    BSTNode* rightChild; //stores the right child
    int data; //stores the data, integer for this project

public:
    //default constructor and destructor
    BSTNode() {leftChild = NULL; rightChild = NULL; data = -1;}
    ~BSTNode() {}

    //setter and getter functions for the private member variables
    void setLeft(BSTNode* left) {this->leftChild = left;}
    void setRight(BSTNode* right) {this->rightChild = right;}
    void setData(int data) {this->data = data;}

    BSTNode* getLeft() const {return leftChild;}
    BSTNode* getRight() const {return rightChild;}
    int getData() const {return data;}
};

#endif /* BSTNode_h */
