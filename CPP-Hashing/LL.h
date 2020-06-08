#ifndef LL_h
#define LL_h

#include "Node.h"
//This linked list employs a sentinal node in the head
//The head is pointing to an empty node
class LL {
    
private:
    Node* head;
    Node* tail;
public:
    //default contructor and destructor
    LL();
    
    //additional functions
    void push_back(string data); //push_back function
    bool contains(string data); //checks if this list contains param data
    void clear(); //clears the list
    string remove_front() ; //removes the front element and returns the removed data
    bool empty(); //returns true if the list is empty
    
    
    Node* getHead() {return head;}
};

#endif /* LL_h */
