#ifndef MTFLIST_H_
#define MTFLIST_H_


#include <fstream>
#include <vector>
#include <string>
#include "Node.h"
/*
 *
 * MTFList class declaration
 *
 *
 */

class MTFList{
private:
	unsigned long count; 	//the number of object on the list
	Node *head;			//the address of the header

public:
	MTFList() {count = 0; head = new Node();} //default constructor
	void readFile(string fileName);//reads in the file
	Node* getHead() const {return head;} //returns the head pointer

	void add(int data); //adds an element to the list
	int search(int data); //searches for an element in the list
	void printList(); //print the current list

};

#endif /* MTFLIST_H_ */
