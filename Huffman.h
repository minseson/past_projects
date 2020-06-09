#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include "PriorityQueue.h"

class Huffman {
private:
	Node* head; //points to the top of the huffman algorithm's binary tree

	int display(Node*, int[], int);
	void printArray(int[], int);
public:
	Huffman();
	Huffman(PriorityQueue);

	int display();
};

#endif /* HUFFMAN_H_ */
