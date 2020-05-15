#include "LL.h"
//Default constructor for linked list
LL::LL()
{
    this->head = NULL;
    this->tail = NULL;
}//END LL()

//This function addss an element at the end of the list
void LL::push_back(string data)
{
    //if this list is empty
    if(head == NULL)
    {
        head = new Node(data);
        tail = head;
    }
    //list has at least one element
    else
    {
        Node* temp = new Node(data);
        tail->setNext(temp);
        tail = temp;
    }
}//END void push_back(string data)

//This function returns true if the list contains the data
bool LL::contains(string data)
{
    //if the list is empty
    if(!this->empty() && data != "")
    {
        Node* temp = this->head;
        //while loop runs until temp reaches the end of the list
        //or it finds the matching data
        while(temp != NULL)
        {
            if(temp->getData() == data)
            {
                return true;
            }
            temp = temp->getNext();
        }//END while(temp != NULL)
    }
    
    //else either the list is empty or the data is an empty string
    return false;
}//END bool contains(string data)

//This function clears the list
void LL::clear()
{
    Node* temp = this->head;
    while (temp != NULL)
    {
        head = head->getNext();
        delete temp;
        temp = head;
    }
    delete head;
}//END void clear()

//This function removes the element in the front
//This function removes the first element in the list
string LL::remove_front()
{
    string deleting = "";
    if(!this->empty())
    {
        deleting = this->head->getData();
        Node* temp = head;
        this->head = head->getNext();
        delete temp;
        if(head == NULL)
        {
            tail = NULL;
        }
    }
    
    return deleting; //if the list is empty
}//END string remove_front()

//This function returns true if the list is empty
bool LL::empty()
{
    if(head == NULL)
    {
        return true;
    }
        
    return false;
    
}//END bool empty()
