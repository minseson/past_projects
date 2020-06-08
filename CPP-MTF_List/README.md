## CPP - Move To Front list

- [Description](#description)
- [Specification](#specification)

## Description

This is an efficient implementation of Move to Front list in C++. Move to Front list is a type oflinear data structure that self-organizes and reorders its items based on an algorithm that moving more frequently accessed element to the front to improve average access time. It reaches closely to a constant time for best cases of accessing elements. 

## Specification

### Sample Input File

The input file is received as the second argument. If no file is passed the program does not run. If there are more than one file's directory in the argument, only the first one is used.
```
10                   <- number of elements in the list
7 9 3 4 2 1 6 0 8 5  <- elements in the list
2                    <- number of searches
7 7                  <- elements to be searched
```

### Sample Output

```
List after Additions: 5 8 0 6 1 2 4 3 9 7
List after Queries: 7 5 8 0 6 1 2 4 3 9
Traversal Count: 11
```

### Structure and Operations

- A linked list is implemented to store the elements.
    - It has the following main methods:
    -   Add
    -   Search 
    -   Print

