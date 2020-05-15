#include "Huffman.h"
Huffman::Huffman()
{
	head = NULL;
}//END default constructor Huffman class

//validity of ifstream will be checked in the main function
//this builds the priorityqueue object
Huffman::Huffman(PriorityQueue pq)
{
	while(!pq.isLeaf(0))
	{
		Node* left = pq.deleteMin();
		Node* right = pq.deleteMin();

		//we are assuming that backslash character does not exist in the file
		Node* root = new Node('\\', left->getPriority()+right->getPriority());
		root->setLeft(left);
		root->setRight(right);

		pq.add(root);
		head = root;
	}//END while(!pq.isLeaf(0))
}//END constructor with a PriorityQueue object


int Huffman::display()
{
	int arr[12] = {};
	int top = 0;
	int compressedBytes = display(head, arr, top)/8;
	cout << "\nUsing this encoding, the characters could be compressed into ";
	cout << compressedBytes << " bytes." << endl;

}//END void display()

int Huffman::display(Node* root, int arr[], int top)
{
	int bits = 0;
	if(root->getLeft() != NULL)
	{
		arr[top] = 0;
		bits += display(root->getLeft(), arr, top+1);
	}

	if(root->getLeft() != NULL)
	{
		arr[top] = 1;
		bits += display(root->getRight(), arr, top+1);
	}

	if(!(root->getLeft()) && !(root->getRight()))
	{
		cout << root->getChar() << "\t";
		printArray(arr, top);
		cout << "\t" << root->getPriority() << endl;
		bits += top * root->getPriority();
		return bits;
	}

	return bits;
}//END void display(Node* root, int arr[], int top)

void Huffman::printArray(int arr[], int size)
{
	string tbp = "";
	for(int i = 0; i < size; i++)
	{
		tbp += to_string(arr[i]);
	}//END for(int i = 0; i < size; i++)

	cout << left << setw(20) << tbp;
}//END printArray(int arr[], int size)
