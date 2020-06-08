#ifndef BST_h
#define BST_h
#include "BSTNode.h"


class BST {
private:
    BSTNode* root;
    int traversalCount;
public:
    BST(){root = NULL; traversalCount = 0;}
    
    void readFile(string filename);
    
    BSTNode* insert(BSTNode* root, int data);
    BSTNode* remove(BSTNode* node, int data);
    
    BSTNode* search(BSTNode* node, int data);
    
    ostream& display(ostream & os = cout) const;
    void display(BSTNode* node, ostream & os) const;
    
    BSTNode* findMin(BSTNode* node);
    BSTNode* findMax(BSTNode* node);
    
    int getTraversalCount() const {return traversalCount;} 
};


#endif /* BST_h */
