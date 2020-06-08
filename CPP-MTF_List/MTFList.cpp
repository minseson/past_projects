#include "MTFList.h"

//void readFile(string filename) method
//this function gets a string that stores the filename
void MTFList::readFile(string filename)
{
	//fstream to open the file
	fstream inFile;
	//open the inFile
	inFile.open(filename.c_str());


	if(!inFile){
		//if the file cannot be opened
		cout << "ERROR: The file could not be opened." << endl;
	} else {

		//reading in the count (size of the list)
		inFile >> count;

		//head is set to NULL here
		head = NULL;
		//for-loop runs for the number of the size
		for(unsigned i = 0; i < count; i++)
		{
			int tempInt = -1;
			inFile >> tempInt;
			//calls MTFList's function called add
			this->add(tempInt);
		}

		//printing the list after adding all the elements
		cout << "List after Additions: ";
		this->printList();

		//evoking the search function
		int findCount = -1;
		int traversalCount = 0;
		inFile >> findCount;
		//the for-loop will run for the findcount that is
		//read from the file
		for(int i = 0; i < findCount; i++)
		{
			int toBeFound = -1;
			inFile >> toBeFound;
			traversalCount += this->search(toBeFound);
		}

		//printing the list after searching
		cout << "List after Queries: ";
		this->printList();
		//printing the traversal count
		cout << "Traversal Count: " << traversalCount << endl;
	}
}//END MTFList::readFile(string filename)

//void add(int data) function
//this adds the element read from file
//in the original order as the file
void MTFList::add(int data)
{
	//if head is NULL
	if(head == NULL){
		head = new Node();
		head->setData(data);
	}
	//if head is not NULL
	else {
		//make a new node to store the new element
		Node *temp = new Node();
		temp->setData(data);

        
		temp->setNext(head);
		temp->setPrev(NULL);
        head->setPrev(temp);
        
        head = temp;
	}
}//END MTFList::add(int data)

//int search(int data) function
//it returns the traversal count
//This function searches for the data
//passed as the parameter
//if not found, it will return the size of the list
int MTFList::search(int data)
{
	//initial traversal count is zero
	int traversalCount = 0;
	Node* temp = head;
	while(temp !=NULL)//while loop runs as long as temp is not NULL
	{
		//traversal count increments everytime it enters the while loop
		traversalCount++;
		if(data == temp->getData())
		{
			if(temp->getData() == head->getData())
			{
				//No need to edit the list
			} else if(temp->getNext() == NULL) {
				//moving the last element to the front
				temp->getPrev()->setNext(NULL);
				temp->setPrev(NULL);
				temp->setNext(head);
				head->setPrev(temp);
				head = temp;
			} else {
				//moving the element in the middle to the front
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
				temp->setPrev(NULL);
				temp->setNext(head);
				head->setPrev(temp);
				head = temp;
			}
			return traversalCount;
		}
		temp = temp->getNext();
	}

	//returns the traversal count
	return traversalCount;
}//MTFList::search(int data)


//void printList()
//this function prints the current list
void MTFList::printList()
{
	Node* temp = new Node();
	temp = head;
	cout << temp->getData() << " ";
	while(temp->getNext()!= NULL)
	{
		temp = temp->getNext();
		cout << temp->getData() << " ";
	}
	cout << endl;
}//END MTFList::printList()






