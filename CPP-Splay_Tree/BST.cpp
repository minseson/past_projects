#ifndef _BST_CPP_
#define _BST_CPP_


#include "BST.h"

//BST::readFile(string) function implementation
void BST::readFile(string filename)
{
    ifstream in;
    in.open(filename.c_str());
    
    
    if(!in)//if file could not be opened
    {
        cout << "ERROR: File could not be opened." << endl;
    } else {
        
        //local variables
        int temp = 0;
        string buffer = " ";

        //initialize the root here
        in >> temp;
        this->root = new BSTNode();
        this->root->setData(temp);
        
        //initializing the tree
        while(in >> buffer && buffer != "$") {
            temp = stoi(buffer); //converts string numeric to temp
            this->insert(this->root, temp);
        }
        
        //displays the tree after initilized
        cout << "BST AFTER INITILIZATION:" << endl;
        this->display();


        //searching initiated
        while(in >> buffer && buffer != "$")
        {
            temp = stoi(buffer);
            this->search(this->root, temp);
        }
        
        //removal initiated
        while(in >> temp)
        {
            this->remove(this->root, temp);
        }
        
        //displays the tree after search and remove sequences
        cout << endl << "BST AFTER SEARCH AND REMOVE SEQUENCES:" << endl;
        this->display();
    }
}//END readFile(string)


//BST::insert(BSTNode*, int) function implementation
//inserts a number by creating a new BSTNode
//assumes that no same data are entered more than once
//follows BST rule
BSTNode* BST::insert(BSTNode* node, int data)
{
    //increme ts traversal count here
    traversalCount++;
    
    //if the root is not empty
    if (node == NULL)
    {
        node = new BSTNode();
        node->setData(data);
        node->setLeft(NULL);
        node->setRight(NULL);
    } else if (data < node->getData()) {
            node->setLeft(insert(node->getLeft(), data));
    } else if (data > node->getData()) {
            node->setRight(insert(node->getRight(), data));
    }
    return node;
}//END insert(BSTNode*, int)

//BST::remove(BSTNode*, int) function implementation
//removes a node that contains data
//follows BST rule
BSTNode* BST::remove(BSTNode* node, int data)
{
    //if the node is empty, then return NULL
    if (node == NULL)
    {
        return NULL;
    }
    //if the data is smaller than this node
    else if (data < node->getData())
    {
        traversalCount++;
        node->setLeft(remove(node->getLeft(), data));
    }
    //if the data is greater than this node
    else if (data > node->getData())
    {
        traversalCount++;
        node->setRight(remove(node->getRight(), data));
    }
    //if the data is same as the node's
    else
    {
        traversalCount++;
        //node with only one child
        if (node->getLeft() == NULL)
        {
            BSTNode *temp = node->getRight();
            free(node);
            return temp;
        }
        else if (node->getRight() == NULL)
        {
            BSTNode *temp = node->getLeft();
            free(node);
            return temp;
        }
        
        //node with two children
        BSTNode* temp = findMin(node->getRight());
        //copy the data of the successor
        node->setData(temp->getData());
        //delete the successor
        node->setRight(remove(node->getRight(), temp->getData()));
    }
    return node;
}//END remove(BSTNode*, int)

//BST::search(BSTNode*, int) function implementation
//searches for data passed as the parameter
BSTNode* BST::search(BSTNode* node, int data)
{
    //increme ts traversal count here
    
    
    //if node does not contain any data
    if (node == NULL)
        return NULL;
    //if node's data matches to the parameter
    else if(node->getData() == data)
    {
        traversalCount++;
        return node;
    }
    //if node's data is smaller than the parameter
    else if(node->getData() < data)
    {
        traversalCount++;
        return search(node->getRight(), data);
    }
    //if node's data is larger than the parameter
    else
    {
        traversalCount++;
        return search(node->getLeft(), data);
    }
}//END search(Node*, int)

//BST::display(ostream&) const funtion implementation
//displays the whole list
ostream& BST::display(ostream & os) const
{
    //if the tree is empty
    if(this->root == NULL)
	{
		os << "ERROR: THIS TREE IS EMPTY" << endl;
	} else {
		display(this->root, os);
        os << endl;
	}
    
    return os;
}//END display(ostream&) const
 
//BST::display(BSTNode*, ostream& os) const function implementation
//recursive preorder traversal display implementation
//displays the list from node
void BST::display(BSTNode* node, ostream& os) const
{
    os << "[";
	if(node != NULL)
	{
        os << node->getData();
        display(node->getLeft(), os);
		display(node->getRight(), os);
	}
    os << "]";
}//END display(Node*, ostream&) const

//BST::findMin(BSTNode*) const function implementation
//returns the node of the minimum value from the parameter
BSTNode* BST::findMin(BSTNode* node)
{
    while(node->getLeft() != NULL)
    {
        traversalCount++;
        node = node->getLeft();
    }
    
    return node;
}//END findMin(Node*) const

//BST::findMax(Node*) const function implementation
//returns the node of the maximum value from the parameter
BSTNode* BST::findMax(BSTNode* node)
{
    while(node->getRight() != NULL)
    {
        traversalCount++;
        node = node->getRight();
    }
    return node;
}//END findMin(BSTNode*) const


#endif
