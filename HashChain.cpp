#include "HashChain.h"

//default constructor implementation
HashChain::HashChain()
{
    this->table = new LL*[TABLE_INITIAL_SIZE];
    this->capacity = TABLE_INITIAL_SIZE; //the table is empty
    this->size = 0; //the table is set to the initial size
    
    for(int i = 0; i < capacity; i++)
    {
        table[i] = new LL();
    }
}//END HashChain::HashChain()

//default destructor implementation
//deallocates all the memories used
HashChain::~HashChain()
{
    for(int i = 0; i < this->capacity; i++)
    {
        if(table[i] != NULL)
        {
            table[i]->clear();
        }
    }//END for(int i = 0; i < TABLE_SIZE; i++)
}//END HashChain::~HashChain()

//This function rehashes
//with the capacity more than twice greater and is prime
void HashChain::rehash()
{
    //the new capacity is the next prime number
    //that's greater than double of the old capacity
    int oldCapacity = capacity;
    this->capacity = nextPrime(this->capacity * 2);
    size = 0;
    
    LL **tempTable = this->table;
    this->table = new LL*[capacity];
    
    for(int i = 0; i < capacity; i++)
    {
        table[i] = new LL();
    }
    
    for(int i = 0; i < oldCapacity; i++)
    {
        while(!tempTable[i]->empty())
        {
            string tempString = tempTable[i]->remove_front();
            add(tempString);
        }//END while(!tempTable[i]->empty())
    }//END for(int i = 0; i < TABLE_SIZE; i++)
    
    delete []tempTable;
}//END void rehash()

//This function returns the next prime number after the int param
int HashChain::nextPrime(int num)
{
    if(num <= 1)
        return 2;
    
    int prime = num;
    while(true)
    {
        prime++;
        
        if(isPrime(prime))
        {
            break;
        }
    }
    
    return prime;
}//END HashChain::nextPrime(int num)

//This function returns if the int param is a prime number
bool HashChain::isPrime(int num)
{
    if(num <= 1)
        return false;
    else if (num<= 3)
        return true;
    
    //check if num is divisible by 2 or 3
    if(num % 2 == 0 || num % 3 == 0)
        return false;
    
    //5 is the next prime number after 2 and 3
    for(int i = 5; i*i <= num; i += 6)
    {
        if(num % i == 0 || num % (i+2) == 0)
        {
            return false;
        }
    }//END for(int i = 5; i*i <= num; i += 6)
    
    return true;
}//END HashChain::isPrime(int num)

//add function implementation
//This function returns the data (a string word)
bool HashChain::search(string data) const
{
    int hashKey = key(data);
    return table[hashKey]->contains(data);
}//END HashChain::search(int key)


//search function implementation
//This function adds a word to the hash
void HashChain::add(string data)
{
    int hashKey = key(data);
    
    //if this section of the table is empty
    //and the size reaches the capacity
    if(table[hashKey]->empty() && ++size >= capacity)
    {
        rehash();
    }
    table[hashKey]->push_back(data);
}//END HashChain::add(int key, string data)


//This function generates a key for the param string word
//Hash function
int HashChain::key(const string &data) const
{
    unsigned int hash = 0;
    for (unsigned i = 0; i < data.length(); i++)
    {
    	char ch = data.at(i);
        ch = tolower(ch);
        hash += hash * 37 + ch;
    }//END for (char ch : word)
    
    return hash % (this->capacity);
}//END HashChain::key(string word)
