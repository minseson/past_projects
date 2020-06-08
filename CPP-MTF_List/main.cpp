#include "main.h"

int main(int argc, char *argv[] ) {

	//if the file name is not entered
	if(argc < 2)
	{
		cout << "ERROR: No file inserted." << endl;
	} else {

		//only reads in the first file
        string filename = argv[1];
		//instantiate a Move-to-front list variable
		MTFList list;
		//reads in the file via calling readFile function of MTFList variable
		list.readFile(filename);
	}

	//returns 0 if not interrupted
	return 0;
}
