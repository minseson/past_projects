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
    unsigned long findCount;//the number of objects to be found
	Node *head;			//the address of the header
    int *findList;      //stores the integers to be found

public:
	MTFList() {count = 0; head = new Node();} //default constructor
	void readFile(string fileName);//reads in the file
	Node* getHead() const {return head;} //returns the head pointer

	void add(int data); //adds an element to the list
	void search(); //searches for an element in the list
	void printList(); //print the current list

};

#endif /* MTFLIST_H_ */
