//
//  SplayBST.h
//  p2
//
//  Created by Minseo Kang on 2/17/20.
//  Copyright © 2020 Minseo Kang. All rights reserved.
//

#ifndef SplayTree_h
#define SplayTree_h
#include "BSTNode.h"

class SplayTree {
private:
    BSTNode* root;
    int traversalCount;
public:
    SplayTree(){root = NULL; traversalCount = 0;}
    
    void readFile(string filename);
    
    BSTNode* insert(BSTNode* root, int data);
    BSTNode* remove(BSTNode* node, int data);
    
    BSTNode* search(BSTNode* node, int data);
    
    ostream& display(ostream & os = cout) const;
    void display(BSTNode* node, ostream & os) const;
    
    BSTNode* rightRotate(BSTNode* node);
    BSTNode* leftRotate(BSTNode* node);
    
    BSTNode* splay(BSTNode* node, int data);

    
    BSTNode* findMin(BSTNode* node);
    BSTNode* findMax(BSTNode* node);
    
    int getTraversalCount() const {return traversalCount;}
};

#endif /* SplayBST_h */
