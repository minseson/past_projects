//
//  OrderedList.h
//  p1
//
//  Created by Minseo Kang on 1/25/20.
//  Copyright © 2020 Minseo Kang. All rights reserved.
//

#ifndef OrderedList_h
#define OrderedList_h

#include <fstream>
#include "Node.h"
#include <cmath>

class OrderedList {
    private:
        int     count;     //the number of object on the list
        int*    list;           //the list to hold the list
        int     findCount;    //the number of objects to be found
        int*    findList;   //the list to hold the objects to be found
    
        int     traversalCount;//the number that counts the traversal count in the listo
    
    public:
        OrderedList(); //default constructor
        void    readFile(string fileName);//reads in the file
        void    binarySearch(int low, int high, int middle);//binary search returns the traversal count
        void    search(); //searches for an element in the list
        void    printList(); //print the current list
        void    mergeSort(int low,int high); //implementation of merge sort
        void    merge(int low,int high,int middle);
};

#endif /* OrderedList_h */

