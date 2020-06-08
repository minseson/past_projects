#include "SplayTree.h"

//Opens the file and perform insert, search, remove
//by reading the data from the file
void SplayTree::readFile(string filename)
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
        
        //initializing the tree
        //while loop runs until the buffer reads the $ sign
        while(in >> buffer && buffer != "$") {
            temp = stoi(buffer); //converts string numeric to temp
            this->insert(this->root, temp);
        }
        
        //displays the tree after initilized
        cout << "Splay TREE AFTER INITILIZATION:" << endl;
        this->display();

        //searching initiated
        //while loop runs until the buffer reads the $ sign
        while(in >> buffer && buffer != "$")
        {
            temp = stoi(buffer);
            this->search(this->root, temp);        }
        
        //removal initiated
        while(in >> temp) //while loop runs until in >> temp is assignable
        {
            this->remove(this->root, temp);
        }
        
        //displays the tree after search and remove sequences
        cout << endl << "Splay TREE AFTER SEARCH AND REMOVE SEQUENCES:" << endl;
        this->display();
    }
}//END SplayTree::readFile(string)

//inserts the data following the splay rule
BSTNode* SplayTree::insert(BSTNode* node, int data)
{
    //If tree is empty then allocate a new memory for the node
    if (node == NULL)
    {
        this->root = new BSTNode;
        this->root->setData(data);
        return node;
    }
    //Bring the closest leaf to param
    node = splay(node, data);
 
    //If data is already present in the tree
    //then return
    if (node->getData() == data)
    {
        this->root = node;
        return node;
    }
 
    //Allocate memory for new node
    BSTNode* temp = new BSTNode();
    temp->setData(data);
     
    //If node's key is greater, make
    //node as right child of temp
    //and copy the left child of node to temp
    if (node->getData() > data)
    {
        temp->setRight(node);
        temp->setLeft(node->getLeft());
        node->setLeft(NULL);
    }
    //If node's data is smaller, make node as left child of temp
    //and copy the right child of node to temp
    else
    {
        temp->setLeft(node);
        temp->setRight(node->getRight());
        node->setRight(NULL);
    }
    
    this->root = temp;//the root becomes the inserted number

    return temp; //temp becomes the new root
}//END SplayTree::insert(BSTNode*, int)


//first bring the node that contains data to the root then delete the root
//replace the root by the maximum number from left children of the root
//or the root is the closest number to the int param that is returned by splay
//this is not a recursive function
BSTNode* SplayTree::remove(BSTNode* node, int data)
{
    //if node passed is null
    if(node == NULL)
    {
        return NULL;
    }
    
    //splay with the data
    node = search(node, data);

    if(data == node->getData())
    {
        BSTNode* temp;
        
        //Key is in the tree
        //left child of node does not exist
        //right child of node becomes the root
        if(node->getLeft() == NULL)
        {
            temp = node;
            node = node->getRight();
        } else {
            temp = node;
            node = search(node->getLeft(),data);
            node->setRight(temp->getRight());
        }
        
        free(temp);
        this->root = node;

    }
    
    return node;
}//END SplayTree::remove(BSTNode*,int)

//search function implementation
BSTNode* SplayTree::search(BSTNode* node, int data)
{
    //calls splay and assign the found node as the root
    return (this->root = splay(node, data));
}//END SplayTree::search(BSTNode*,int)

//SplayTree::display(ostream&) const funtion implementation
//displays the whole list
ostream& SplayTree::display(ostream & os) const
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
 
//SplayTree::display(BSTNode*, ostream& os) const function implementation
//recursive preorder traversal display implementation
//displays the list from node
void SplayTree::display(BSTNode* node, ostream& os) const
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

//zig
//right rotate from this node
BSTNode* SplayTree::rightRotate(BSTNode* node)
{
    BSTNode *temp = node->getLeft();
    node->setLeft(temp->getRight());
    temp->setRight(node);
    return temp;
}//SplayTree::rightRotate(BSTNode*)

//zag
//left rotate from this node
BSTNode* SplayTree::leftRotate(BSTNode* node)
{
    BSTNode *temp = node->getRight();
    node->setRight(temp->getLeft());
    temp->setLeft(node);
    return temp;
}//SplayTree::leftRotate(BSTNode*)

BSTNode* SplayTree::splay(BSTNode* node, int data)
{
    traversalCount++;
    //return this node if this node's data matches the param
    //or if it's NULL
    if (node == NULL || node->getData() == data)
        return node;
  
    //if the param is smaller than this node's data
    if (node->getData() > data)
    {
        //if this node does not have any left child
        //return this node
        if (node->getLeft() == NULL) 
        {
            return node;
        }
        //if param is smaller than this node's left child's data
        //zig-zig
        if (node->getLeft()->getData() > data)
        {
            //bring the data as the node of left-left
            node->getLeft()->setLeft(splay(node->getLeft()->getLeft(), data));
            //second rotation is done later if needed
            node = rightRotate(node);
        }
        //if param is greater than this node's left child's data
        //zig-zag
        else if (node->getLeft()->getData() < data)
        {
            //bring the data as node of left-right
            node->getLeft()->setRight(splay(node->getLeft()->getRight(), data));
            if (node->getLeft()->getRight() != NULL)
            {
                node->setLeft(leftRotate(node->getLeft()));
            }
        }
        //second rotation if needed
        return (node->getLeft() == NULL)? node: rightRotate(node);
    }
    //if the param is greater than this node's data
    else
    {
        if (node->getRight() == NULL) return node;
  
        //if param is smaller than this node's right child's data
        //zag-zig
        if (node->getRight()->getData() > data)
        {
            //bring the data as the node of right-left
            node->getRight()->setLeft(splay(node->getRight()->getLeft(), data));
  
            if (node->getRight()->getLeft() != NULL)
            {
                node->setRight(rightRotate(node->getRight()));
            }
        }
        //if param is greater than this node's right child's data
        //zag-zag
        else if (node->getRight()->getData() < data)
        {
            //bring the data as the node of right-right
            node->getRight()->setRight(splay(node->getRight()->getRight(), data));
            node = leftRotate(node);
        }
  
        return (node->getRight() == NULL)? node: leftRotate(node);
    }
}//SplayTree::splay(BSTNode*,int)

//Find the minimum value from this param
//and returns the pointer value to it
BSTNode* SplayTree::findMin(BSTNode* node)
{
    while(node->getLeft() != NULL)
    {
        traversalCount++;
        node = node->getLeft();
    }
    
    return node;
}//END SplayTree::findMin(BSTNode* node)


//Find the maximum value from this param
//and returns the pointer value to it
BSTNode* SplayTree::findMax(BSTNode* node)
{
    while(node->getRight() != NULL)
    {
        traversalCount++;
        node = node->getRight();
    }
    
    return node;
}//END SplayTree::findMax(BSTNode* node)
