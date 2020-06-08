//
//  OrderedList.cpp
//  p1
//
//  Created by Minseo Kang on 1/25/20.
//  Copyright © 2020 Minseo Kang. All rights reserved.
//
#include "OrderedList.h"

//default constructor
OrderedList::OrderedList()
{
    count = 0;
    findCount = 0;
    list = new int[1]; //instantiated as size = 1 but resizes when the file is read
    findList = new int[1]; //instantiated as size = 1 but resizes when the file is read
    traversalCount = 0;
}

//readfile function
//this reads the file in
//file name is passed from main
void OrderedList::readFile(string fileName)
{
    fstream inFile;
    inFile.open(fileName.c_str());
    
    if(!inFile){
        cout << "ERROR: File reading error in OrderedList::readFile(string)" << endl;
    } else {
        //reading in the count (size of the list)
        inFile >> count;

        list = new int[count];
        //for-loop runs for the number of the size
        for(int i = 0; i < count; i++)
        {
            int tempInt = -1;
            inFile >> tempInt;
            //calls MTFList's function called add
            list[i] = tempInt;
        }//END for
        
        mergeSort(0, count - 1);
        cout << "Ordered List after Additions: ";
        this->printList();
        
        inFile >> findCount;
        findList = new int[findCount];
        for(int j = 0; j < findCount; j++)
        {
            int tempData;
            inFile >> tempData;
            findList[j] = tempData;
        }
        
    }//END else
}//END OrderedList::readFile(string)

//mergesort function
void OrderedList::mergeSort(int low, int high)
{
    //if low index is smaller than high index
    if(low < high)
    {
        int middle = low + (high - low) / 2;
        mergeSort(low, middle);
        mergeSort(middle + 1, high);
        merge(low, high, middle);
    }
}

//merge function that is called from mergesort function
void OrderedList::merge(int low, int high, int middle)
{
    
    //temporary variables
    int i, j, k, temp[count];
    i = low;
    k = low;
    j = middle + 1;
    
    
    while (i <= middle && j <= high)
    {
        //traversal count is incremented once here
        traversalCount++;

        //increase the traversal count
        if (list[i] < list[j])
        {
            temp[k] = list[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = list[j];
            k++;
            j++;
        }
    }
    while (i <= middle)
    {
        temp[k] = list[i];
        k++;
        i++;
    }
    
    while (j <= high)
    {
        temp[k] = list[j];
        k++;
        j++;
    }
    
    for (i = low; i < k; i++)
    {
        list[i] = temp[i];
    }
}//END OrderedList::merge(int, int, int)

//binary search function
//because the list is ordered we can employ binary search
void OrderedList::binarySearch(int low, int high, int toBeFound)
{
    bool found = false;
    while (low <= high && !found) {
        
        int mid = low + (high - low) / 2;
    
        // Check if toBeFound is present at mid
        if (list[mid] == toBeFound)
        {
            traversalCount++;
            found = true;
        }
        // If toBeFound greater, ignore left half
        else if (list[mid] < toBeFound)
        {
            traversalCount += 2;
            low = mid + 1;
        }
        // If toBeFound is smaller, ignore right half
        else
        {
            traversalCount += 2;
            high = mid - 1;

        }
      }
}//END binarySearch(int,int,int)

//search function
//this goes through the findList
//findList stores all the objects to be searhed
void OrderedList::search()
{
    bool found = false;
    
    for(int j = 0; j < findCount; j++)
    {
        found = false;
        binarySearch(0, count - 1, findList[j]);
    }
    cout << "Ordered List Traversal Count: " << traversalCount << endl;
}//END OrderedList::search()

//print function
//this prints all the objects in the list
//in the current state
void OrderedList::printList()
{
    for(int i = 0; i < count; i++)
    {
        cout << list[i] << " ";
    }
    
    cout << endl;
}//END OrderedList::printList()

