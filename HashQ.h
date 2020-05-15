#ifndef HashQ_h
#define HashQ_h
#include "Node.h"
#include <cmath>
#include <iomanip>

const int TABLE_INITIAL_CAP = 599;

class HashQ {
private:
    Node** table; //table
    int capacity; //table capacity
    int size; //table size
    int nextPrime(int num); //This function returns the next prime number after num
    bool isPrime(int num); //This function returns true if num is a prime number
    
public:
    //default constructor and destructor
    HashQ();
    ~HashQ();
    
    //additional functions
    bool search(int keyPow, string data) const; //This function returns the data (a string word)
    bool add(int keyPow, string data); //This function adds a word to the hash
    
    int key(const string &data) const;
    void rehash(); //This function rehashes
    
    //basic getter functions
    int getSize() const {return size;}
    int getCapcaity() const {return capacity;}
    
    void display() const;
};

#endif /* HashQ_h */
