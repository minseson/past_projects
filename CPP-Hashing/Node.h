
#ifndef Node_h
#define Node_h

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cctype>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <chrono>
#include <iomanip>


using namespace std;

class Node {
private:
    string data;
    Node* next;
    
public:
    
    //constructors and the default destructor
    Node() {this->data = ""; this->next = NULL;}
    Node(string data) {this->data = data; this->next = NULL;}
    Node(string data, Node* next) {this->data = data; this->next = next;}
    
    
    //basic getter and setter functions for the private member variables
    void setNext(Node* next) {this->next = next;}
    void setData(string data) {this->data = data;}
    Node* getNext() const {return next;}
    string getData() const {return data;}
};

#endif /* Node_h */
