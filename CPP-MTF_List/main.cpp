#include "main.h"

int main(int argc, char *argv[] ) {

	//if the file name is not entered
	if(argc < 2)
	{
		cout << "ERROR: No file inserted." << endl;
	} else {

		//only reads in the first file
        string filename = argv[1];
        
        //chrono timer starts here
        chrono::steady_clock::time_point start2 = chrono::steady_clock::now();
        
        OrderedList oList;
        oList.readFile(filename);
        oList.search();
        
        //chrono timer stops here after ordered list operation ends
        chrono::steady_clock::time_point end2 = chrono::steady_clock::now();
        
        
        
        cout << "Elapsed time for Ordered List: ";
        cout << chrono::duration_cast<chrono::nanoseconds> (end2 - start2).count();
        cout << " ns (nanoseconds)" << endl << endl;
        
        //chrono timer starts here
        chrono::steady_clock::time_point start1 = chrono::steady_clock::now();
        
        //instantiate a Move-to-front list variable
        MTFList list;
        //reads in the file via calling readFile function of MTFList variable
        list.readFile(filename);
        list.search();
        
        //chrono timer stops here after MTF list operation ends
        chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
        
        //output the time
        cout <<"Elapsed time for MTF List: ";
        cout << chrono::duration_cast<chrono::nanoseconds> (end1 - start1).count();
        cout << " ns (nanoseconds)" << endl;
	}

	//returns 0 if not interrupted
	return 0;
}
