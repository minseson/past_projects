#include "main.h"

int main(int argc, const char * argv[]) {
    
    if(argc < 2)
    {
        cout << "ERROR: Not enough argument entered" << endl;
    } else {
        
        //reads the second argument as the filename
        string filename = argv[1];
        
        //chrono timer for BST treestarts here
        chrono::steady_clock::time_point start1 = chrono::steady_clock::now();
        
        BST bst;
        bst.readFile(filename);
        //display the traversal count
        cout << endl << "Traversal Count for basic BST Tree: ";
        cout << bst.getTraversalCount() << endl;
    
        //chrono timer stops here after ordered list operation ends
        chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
        
        
        //output of the time taken for the operation above
        cout << endl << "Elapsed time: for basic BST Tree: ";
        long long bstTime = chrono::duration_cast<chrono::nanoseconds> (end1 - start1).count();
        cout << bstTime;
        cout << " ns (nanoseconds)" << endl;
        
        
        /* ********************************************************************/
        /* ********************************************************************/
        /* ********************************************************************/
        /* ********************************************************************/
        
        
        //chrono timer for Splay BST treestarts here
        chrono::steady_clock::time_point start2 = chrono::steady_clock::now();
       
        SplayTree sBST;
        sBST.readFile(filename);
        //display the traversal count
        cout << endl << "Traversal Countfor Splay Tree: ";
        cout << sBST.getTraversalCount() << endl;
   
        //chrono timer stops here after ordered list operation ends
        chrono::steady_clock::time_point end2 = chrono::steady_clock::now();
       
       
        //output of the time taken for the operation above
        cout << endl << "Elapsed time: for Splay Tree: ";
        long long sBSTTime = chrono::duration_cast<chrono::nanoseconds> (end2 - start2).count();
        cout << sBSTTime;
        cout << " ns (nanoseconds)" << endl << endl;
        
        
        
        //comparing the result
        if(sBSTTime < bstTime)
        {
            cout << "RESULT: Splay tree was faster in ";
            cout << "processing " << filename << " by " << bstTime - sBSTTime;
            cout << " ns (nanoseconds) than basic binary search tree" << endl;
        } else {
            cout << "RESULT: basic binary search tree was faster in ";
            cout << "processing " << filename << "\n by " <<sBSTTime - bstTime ;
            cout << " ns (nanoseconds) than splay tree" << endl;
        }
    }
    return 0;
}
