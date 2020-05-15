#include "main.h"

int main(int argc, const char * argv[]) {
    if(argc < 3)
    {
        cout << "ERROR: Not enough argument entered" << endl;
    } else {
        
        //reads the second argument as the dictionary name
        //reads the third argument as the inputfile name
        string dicName = argv[1];
    	string inName = argv[2];
        
        //ifstreams to open the file
        ifstream dicFile;
        ifstream inFile;
        
        //linked lists to store contents in dicFile and inFile
        LL inLL1;
        LL inLL2;
        
        ifstream dicF; //ifstream for the dictionary
        ifstream inF; //ifstream for the input file
        
        dicF.open(dicName.c_str()); //opening the dictionary file
        inF.open(inName.c_str()); //opening the input file
            
        if(!dicF || !inF) //if either of files do not open
        {
            cout << "ERROR: FILE COULD NOT BE OPENED IN MAIN FUNCTION." << endl;
            return 0;
        }
            
        string buffer = "";
        
        //HASH with chaining strategy
        HashChain hashchain;
        HashQ hashQ;
        
        while(dicF >> buffer)
        {
            //make all letters lowercase
            if(buffer.length() > 0)
            {
                for (unsigned i = 0; i < buffer.length() && isalpha(buffer.at(i)); i++)
                {
                    buffer.at(i) = tolower(buffer.at(i));
                }//END for (int i = 0; i < buffer.length() && isalpha(buffer.at(i)); i++)
            }
            //cout << "ADDED: " << buffer << endl;
            hashchain.add(buffer);
            hashQ.add(0, buffer);
        }//END while(dicF >> buffer)
            


        while(inF >> buffer)
        {
            string prePunct = "";
            string postPunct = "";
            bool punct = false;
            
            for(int i = 0; i < 3; i++)
            {
                //to remove any punctuation in front of any words
                //usuall up to three punctuations
                if(buffer.length() > 1 && ispunct(buffer.at(0)))
                {
                    buffer = buffer.substr(1, buffer.length());
                }
            }
            
            for(int i = 0; i < 3; i++)
            {
                //to remove any puncuations in the back of any words
                if (buffer.length() > 0 && ispunct(buffer.at(buffer.length() - 1 )))
                {
                    buffer = buffer.substr(0,buffer.length() - 1);
                }
            }

            //make all letters lowercase
            if(buffer.length() > 0)
            {
                for (unsigned i = 0; i < buffer.length(); i++)
                {
                    buffer.at(i) = tolower(buffer.at(i));
                }//END for (int i = 0; i < buffer.length() && isalpha(buffer.at(i)); i++)
            }
            
            //detect any words with 's (e.g. grant's -> grant)
            if(buffer.length() > 1)
            {
                if (ispunct(buffer.at(buffer.length() - 2)) && buffer.at(buffer.length() - 1 == 's'))
                {
                    buffer = buffer.substr(0, buffer.length() - 2);
                }
            }
            
            for (unsigned i = 0; i < buffer.length(); i++)
            {
                if (ispunct(buffer.at(i)))
                {
                    punct = true;
                }
                else
                {
                    if(!punct)
                    {
                        prePunct += tolower(buffer[i]);
                    }
                    else
                    {
                        postPunct += tolower(buffer[i]);
                    }
                }
                
            }//END for (int i = 0; i < buffer.length(); i++)
            
            if(prePunct != "")
            {
                inLL1.push_back(prePunct);
                inLL2.push_back(prePunct);
            }
            
            if(postPunct != "")
            {
                inLL1.push_back(postPunct);
                inLL2.push_back(postPunct);
            }
        }
        
        //Hash with chaining strategy searching starts here
        chrono::monotonic_clock::time_point start1 = chrono::monotonic_clock::now();

        int misSpelled1 = 0;
        while(!inLL1.empty())
        {
            if(!hashchain.search(inLL1.remove_front()))
            {
                misSpelled1++;
            }
        }//END for(int i = 0; i < inLL.getSize(); i++)

        chrono::monotonic_clock::time_point end1 = chrono::monotonic_clock::now();
        long long chainTime = chrono::duration_cast<chrono::nanoseconds> (end1 - start1).count();
        cout << "# of misspelled words from hashchain: " << misSpelled1 << endl;

        //output of the time taken for the operation above
        cout << endl << "Elapsed time for Hash with chaining strategy: ";
        cout << chainTime << " ns (nanoseconds)" << endl << endl <<endl;

        //Hash with quadratic probing strategy starts here
        chrono::monotonic_clock::time_point start2 = chrono::monotonic_clock::now();

        int misSpelled2 = 0;
        while(!inLL2.empty())
        {
            if(!hashQ.search(0, inLL2.remove_front()))
            {
                misSpelled2++;
            }
        }//END for(int i = 0; i < inLL.getSize(); i++)

        chrono::monotonic_clock::time_point end2 = chrono::monotonic_clock::now();
        long long qTime = chrono::duration_cast<chrono::nanoseconds> (end2 - start2).count();
        cout << "# of misspelled words from hashQ: " << misSpelled2 << endl;

        //output of the time taken for the operation above
        cout << endl << "Elapsed time for Hash with quadratic probing strategy: ";
        cout << qTime << " ns (nanoseconds)" << endl;
    }

}

