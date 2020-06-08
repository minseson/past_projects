## CPP - Hashing

- [Description](#description)
- [Specification](#specification)

## Description

This is a C++ program that compares the efficiency of two different hash collision handling methods: chaining (closed hashing) and quadratic-probing (open addressing). 

Hashing is used in data structures to map data from an arbitrary value to a fixed value that can be easily accessed. The values are mapped out in a table called hash table. 

Chaining method resolute the collisions by addressing the colliding element to become the next element of the list of the index. In other words, in chaining method, hash table works like an array of linked lists so that each index is the first element of a linked list and colliding element can become the last element of the list. 

Quadratic probing method is one of the open addressing scheme that is often compared with linear-probing for avoiding clustering problem better. If there is a collision, the hash function enters and increased by a square of an integer, rather than incremending by one each time. 


## Specification

### Sample Input File

The input file is received as the second and third arguments. If no file or less than two files are passed the program does not run. If there are more than one file's directory in the argument, only the first one is used.

The first file will be logged as the dictionary and the second file will be an input file to get compared with the dictionary if there is any misspelled word. 

For instance, on the server it would look like this assuming this is compiled as a.out:
```
./a.out sample_dictionary_file.txt sample_input_file.txt
./a.out sample_dictionary_file.txt sample_input_file.txt thisfileisignored.txt
```

An example of dictionary files:
```
hyperconcentration
hypercone
hyperconfident
hyperconformist
hyperconscientious
hyperconscientiousness
hyperconscious
hyperconsciousness
hyperconservatism
hyperconstitutional
hypercoracoid
hypercorrect
hypercorrection
hypercorrectness
```

An example of input files:
```
hyperconcentration
hyperconcentration
hyperconcentration
hyperconcentration
hyperconcentration
hyperconcentration
hyperconcentration
hyperconscientiousness
hyperconscious
hyperconsciousness
hyperconservatism
hyperconstitutional
hypercoracoid
hypercorrect
hypercorrection
hypercorrectness
hyperconscientiousness
hyperconscientiousness
hyperconscientiousness
```

Sample input files are included in the repository called test1.txt and test2.txt.

### Sample Output

```
# of mispelled words from hashchain: 0

Elapsed time for Hash with chaining strategy: 28500 ns (nanoseconds)


MISSPELLED: hyperconsciousness
# of mispelled words from hashQ: 0

Elapsed time for Hash with quadratic strategy: 80582 ns (nanoseconds)
```
