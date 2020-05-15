#include "main.h"

using namespace std;

int main(int argc, char *argv[]) {
	if(argc < 2) //thorws an error when the filename is not passed
	{
		cout << "ERROR: NOT ENOUGH ARGUMENT PASSED." << endl;
		return -1;
	}

	string fName = argv[1]; //second argument is the filename passed
	ifstream in; //ifstream to open the file
	int tempfreq[256] = {}; //temporary integer array to store the frequency

	in.open(fName.c_str()); //file is opened here

	if(!in) //if the file could not be opened
	{
		cout << "ERROR: FILE COULD NOT BE OPENED." << endl;
		return -2;
	}

	//runs for 256 times because there are only 256 ANSI characters
	for(int i = 0; i < 256; i++)
	{
		tempfreq[i] = 0;
	}//END for(int i = 0; i < 256; i++)

	//temporary string object to read the file in
	string buffer;
	char temp;
	while(getline(in, buffer, '\n'))
	{
		for(unsigned j = 0; j < buffer.length(); j++)
		{
			temp = buffer.at(j);
			tempfreq[int(temp)]++;
		}
	}//END while(getline(in, buffer, '\n'))

	//temporary vector objects to store the char characters and frequencies in integer
	vector<char> vData;
	vector<int> vFreq;
	int sz = 0; //size of the vectors

	//runs for 256 times because there are only 256 ANSI characters
	for(int i = 0; i < 256; i++)
	{
		if(tempfreq[i] != 0)
		{
			sz++;
			vData.push_back(char(i));
			vFreq.push_back(tempfreq[i]);
		}
	}//END for(int i = 0; i < 256; i++)

	char data[sz] = {};
	int freq[sz] = {};

	for(int k = 0; k < sz; k++)
	{
		data[k] = vData.at(k);
		freq[k] = vFreq.at(k);
	}//END for(int k = 0; k < sz; k++)


	//priorityqueue is built here
	PriorityQueue pq;
	pq.buildHeap(data, freq, sz);


	Huffman huffman(pq); //huffman algo object is defined here
	huffman.display(); //display the tree as specified

	return 0;
}
