#include "HashQ.h"

//Default contructor
HashQ::HashQ()
{
    table = new Node*[TABLE_INITIAL_CAP]; //table
    capacity = TABLE_INITIAL_CAP; //table capacity
    size = 0; //table size
    
    for(int i = 0; i < capacity; i++)
    {
        table[i] = NULL;
    }
}

//Default constructor for HashQ class
HashQ::~HashQ()
{
    delete []table;
}//END HashQ::~HashQ()

//This function adds a word to the hash
//add function implementation
//a recursive function
//initially keyPow is 0
bool HashQ::add(int keyPow, string data)
{
	//quadratic probing
	//keyPow is initially zero
    int hashKey = key(data) + pow(keyPow, 2);
    
    while(hashKey > capacity)
    {
        rehash();
    }
    
    if(table[hashKey] == NULL)
    {
        if(++size / capacity >= 0.5)
        {
            rehash();
        }
        table[hashKey] = new Node(data);
        return true;
    } else {
    	return add(keyPow+1, data);
    }

    return false;

}//END void add(string data)


//This function returns the data (a string word)
//search function implementation
bool HashQ::search(int keyPow, string data) const
{
    int hashKey = key(data) + pow(keyPow, 2);
    if(hashKey < capacity)
    {
        if(table[hashKey] != NULL){
            if(table[hashKey]->getData() == data)
            {
                return true;
            } else {
                return search(keyPow+1, data);
            }
        }
    }
    return false;
}//END HashQ::search(int key)


//This function rehashes
//with the capacity more than twice greater and is prime
void HashQ::rehash()
{
    //the new capacity is the next prime number
    //that's greater than double of the old capacity
    int oldCapacity = capacity;
    this->capacity = nextPrime(this->capacity * 2);
    size = 0;
    
    Node **tempTable = this->table;
    this->table = new Node*[capacity];
    
    for(int i = 0; i < capacity; i++)
    {
        table[i] = NULL;
    }//END for(int i = 0; i < capacity; i++)
    
    for(int i = 0; i < oldCapacity; i++)
    {
        if(tempTable[i] != NULL)
        {
            add(0, tempTable[i]->getData());
        }
    }//END for(int i = 0; i < oldCapacity; i++)
    
    delete []tempTable;
}//END void rehash()


//This function generates a key for the param string word
//Hash function
int HashQ::key(const string &data) const
{
    unsigned int hash = 0;
    for (unsigned i = 0; i < data.length(); i++)
	{
    	char ch = data.at(i);
		ch = tolower(ch);
		hash += hash * 37 + ch;
   }//END for (char ch : word)
   
   return hash % (this->capacity);
}//END HashQ::key(string word)



//This function returns the next prime number after the int param
int HashQ::nextPrime(int num)
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
}//END HashQ::nextPrime(int num)

//This function returns if the int param is a prime number
bool HashQ::isPrime(int num)
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
}//END HashQ::isPrime(int num)


