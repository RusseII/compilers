# A Simple Compiler Lexer Implementation 
###### by Russell Ratcliffe

## How to run program on Linux
```
$ git clone https://github.com/russeii/compilers
$ cd compilers
$ mkdir make
$ cd make
$ cmake ..
$ make
$ ./bool
```
###Input
Input comes from stdin, accepts numbers and most common mathmatical operators

#Output
A vector of tokens of the form < kind, attribute >

## Implementation
The punctuators and operators for this language are defined in the `lex.hpp` file.
The integer literals are 0-9 and the boolean literals are true and false.
Most of my lexer implementation is in `lex.hpp` I 
 
