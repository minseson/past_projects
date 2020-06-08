#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>
#include <exception>

using namespace std;

/*
 *
 *
 * Node class declaration
 */
class Node {
private:
	Node* next; //stores the next element
	Node* prev; //stores the previous element
	int data; //stores the data, integer for this project

public:
	Node(); //default constructor

	//setter and getter functions for the private member variables
	void setNext(Node* next) {this->next = next;}
	void setPrev(Node* prev) {this->prev = prev;}
	void setData(int data) {this->data = data;}

	Node* getNext() const {return next;}
	Node* getPrev() const {return prev;}
	int getData() const {return data;}
};





#endif /* NODE_H_ */
