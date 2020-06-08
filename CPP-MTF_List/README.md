## CPP - Move To Front list

- [Description](#description)
- [Specification](#specification)
- [Analysis](#analysis)

## Description

This is a C++ program that compares the efficiency of data structures of Move-To-Front list and an ordered list in integers ascending order. 

Move to Front list is a type oflinear data structure that self-organizes and reorders its items based on an algorithm that moving more frequently accessed element to the front to improve average access time. It reaches closely to a constant time for best cases of accessing elements. 

## Specification

### Sample Input File

The input file is received as the second argument. If no file is passed the program does not run. If there are more than one file's directory in the argument, only the first one is used.
For instance, on the server it would look like this assuming this is compiled as a.out:
```
./a.out samplefile.txt
./a.out samplefile.txt thisfileisignored.txt thisfileisignored.txt
```

An example of input files:
```
12                          <- number of elements in the list
1 2 3 4 5 6 7 8 9 0 10 11   <- elements in the list
3                           <- number of searches
8 10 8                      <- elements to be searched
```
Sample input files are included in the repository called poisson.txt and uniform.txt.

### Sample Output

```
Ordered List after Additions: 0 1 2 3 4 5 6 7 8 9 10 11 
Ordered List Traversal Count: 37
Elapsed time for Ordered List: 9377477 ns (nanoseconds)

MTF List after Additions: 11 10 0 9 8 7 6 5 4 3 2 1 
MTF List after Queries: 8 10 11 0 9 7 6 5 4 3 2 1 
MTF List Traversal Count: 10
Elapsed time for MTF List: 362237 ns (nanoseconds)
```

### Structure and Operations

- A linked list is implemented to store the elements.
    - It has the following main methods:
    -   Add
    -   Search 
    -   Print

#### Sorting and Searching methods for ordered list
An ordered list can employ many different sorting and searching methods. 
This program uses a merge sort to sort items and binary search since it is efficient when the list is sorted.


## Analysis

### MTFList
I employed nodes which is easier to move the object around the list and increase the time efficiency. Space
complexity for search function in MTFList is O(1) and time complexity of O(n).

### OrderedList
Using array is easier to access the objects in the list and compare the values. Time complexity for search
O(nlog(n)) (binary search) and the time complexity is O(n). I used binary search because the list is ordered and it is more
efficient than linear search. I employed merge sort to sort the numbers in the list which has high space complexity but low
time complexity. Their Big-O complexities are as follows: Space complexity for mergeSort: O(n): Binary search is efficient
with time complexity of O(log(n))

### Result
Ordered list is generally faster in time-wise with less traversal count in comparison to MTF list. Although space
complexity for ordered list is larger than MTF list, but it is better if time management is more important than using more
space. Also, ordered list has its element in the order which enables it to employ binary search rather than linear search,
which increases the time efficiency.
