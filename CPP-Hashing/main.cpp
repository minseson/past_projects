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
            cout << "ERROR: FILE COULD NOT BE OPENED IN HASHCHAIN READ FUNCTION." << endl;
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
                for (int i = 0; i < buffer.length() && isalpha(buffer.at(i)); i++)
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
                for (int i = 0; i < buffer.length(); i++)
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
            
            for (int i = 0; i < buffer.length(); i++)
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
        
        chrono::steady_clock::time_point start1 = chrono::steady_clock::now();
        

        int misSpelled = 0;
        while(!inLL1.empty())
        {
            buffer = inLL1.remove_front();
            if(!hashchain.search(buffer))
            {
                cout << "MISSPELLED: " << buffer << endl;
                misSpelled++;
            }
        }//END for(int i = 0; i < inLL.getSize(); i++)

        chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
        long long chainTime = chrono::duration_cast<chrono::nanoseconds> (end1 - start1).count();
        cout << "# of mispelled words from hashchain: " << misSpelled << endl;
        
        //output of the time taken for the operation above
        cout << endl << "Elapsed time for Hash with chaining strategy: ";
        cout << chainTime << " ns (nanoseconds)" << endl << endl <<endl;
        
        
        
        
        
        
        
        
        chrono::steady_clock::time_point start2 = chrono::steady_clock::now();
        
//        cout << endl;
//        hashQ.display();
//        cout << endl;



        misSpelled = 0;
        while(!inLL2.empty())
        {
            buffer = inLL2.remove_front();
            if(!hashQ.search(0, buffer))
            {
                cout << "MISSPELLED: " << buffer << endl;
                misSpelled++;
            }
        }//END for(int i = 0; i < inLL.getSize(); i++)
        
        
        
        chrono::steady_clock::time_point end2 = chrono::steady_clock::now();
        long long qTime = chrono::duration_cast<chrono::nanoseconds> (end2 - start2).count();
        cout << "# of mispelled words from hashQ: " << misSpelled << endl;
        
        //output of the time taken for the operation above
        cout << endl << "Elapsed time for Hash with quadratic strategy: ";
        cout << qTime << " ns (nanoseconds)" << endl;
    }

}

