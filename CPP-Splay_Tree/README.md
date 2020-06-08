## CPP - Splay Tree

- [Description](#description)
- [Specification](#specification)
- [Analysis](#analysis)

## Description

This is a C++ program that compares the efficiency of data structures of a simple binary search tree and a splay tree.

Binary tree is a structure like a tree but each node can have only upto one parent node, except the root, and two children nodes. 
Binary search tree is a type of a data structure that each node stores a data (integer for this practice) and it stores a lesser key as its left child and greater key as the right child. (https://en.wikipedia.org/wiki/Binary_search_tree)

Splay tree is a type of a data structure that employes binary search tree with an additional function called "splay." Splay function is accessed whenever an element is added to the tree or an element is accessed so it moves to the top. It offers a Big-O time complexity of O(Log N) in both average and worst cases. 

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

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 <- elements in the list
$                                   <- line separator
5 4 3 5 7 13                        <- elements to be searched
$                                   <- line separator
11 6 7 2 12 6                       <- elements to be deleted
```
Sample input files are included in the repository called test1.txt and test2.txt.

### Sample Output

```
BST AFTER INITILIZATION:
[1[][2[][3[][4[][5[][6[][7[][8[][9[][10[][11[][12[][13[][14[][15[][]]]]]]]]]]]]]]]]

BST AFTER SEARCH AND REMOVE SEQUENCES:
[1[][3[][4[][5[][8[][9[][10[][13[][14[][15[][]]]]]]]]]]]

Traversal Count for basic BST Tree: 194

Elapsed time: for basic BST Tree: 589756313648 ns (nanoseconds)
Splay TREE AFTER INITILIZATION:
[15[14[13[12[11[10[9[8[7[6[5[4[3[2[1[][]][]][]][]][]][]][]][]][]][]][]][]][]][]][]]

Splay TREE AFTER SEARCH AND REMOVE SEQUENCES:
[8[4[1[][3[][]]][5[][]]][10[9[][]][13[][14[][15[][]]]]]]

Traversal Countfor Splay Tree: 52

Elapsed time: for Splay Tree: 580888 ns (nanoseconds)

RESULT: Splay tree was faster in processing p2_test0.txt by 589755732760 ns (nanoseconds) than basic binary search tree
```

### Structure and Operations

- A binary search tree structure is employed to store data.
- Traversal Count is incremented whenever an element is accessed.

#### Operations
The output in brakets show the structure of a binary tree. The visualization can be done on the Syntax Tree Generator Website (http://mshang.ca/syntree/).
