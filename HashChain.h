#ifndef HashChain_h
#define HashChain_h

#include "LL.h"


const int TABLE_INITIAL_SIZE = 599;

class HashChain {
private:
    LL** table; //table
    int capacity; //table capacity
    int size; //table size
    int nextPrime(int num); //This function returns the next prime number after num
    bool isPrime(int num); //This function returns true if num is a prime number
    
    
public:
    //default constructor and destructor
    HashChain();
    ~HashChain();
    
    //additional functions    
    bool search(string data) const; //This function returns the data (a string word)
    void add(string data); //This function adds a word to the hash
    
    int key(const string &word) const;
    void rehash(); //This function rehashes
    
    //basic getter functions
    int getSize() const {return size;}
    int getCapcaity() const {return capacity;}
    
};

#endif /* HashChain_h */
