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
Most of the lexer implementation is in `lex.hpp` there is an enumerated type which holds all
possible types in this language that can be referenced
I have a `Token` struct that defines the properties of a token. A token has a `kind` member variable 
which refers to the type of token it is. It also has an att attribute member variable which refers to the 
tokens attribute.

There is another struct named `Lexer` which has three member variables, first, last, and chars. First and last
are pointers to the first and last character in a string, and chars holds the current numbers that are being 
analyzed. `Lexer` contains default constructer for taking a string, and it sets the value of first and last.
`Lexer` also contains a function `consume` for iterating the char pointer to point to the next character
in the string. It also contains a member function for looking at the character stored at first 

There is also a function next which returns a Token pointer. It contains a switch
statement that is triggered based on the value of the current character. This is what is used
for detecting operators/numbers/literals
 
