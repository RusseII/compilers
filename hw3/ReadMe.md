# A Simple Compiler Lexer Implementation 
###### by Russell Ratcliffe

## How to run program on Linux
```
$ git clone https://github.com/russeii/compilers
$ cd compilers
$ cd hw3 
$ mkdir make
$ cd make
$ cmake ..
$ make
$ ./bool
```

## Implementation
Parser is defined in `parser.hpp`. The parser object takes a vector of tokens that are created by the lexer defined in `lexer.hpp`.
The helper function `lookahead` peaks at next token in the deque. `consume` pops the head token off the deque. The `match` function is used to check the current token type this is very useful because it allows you to easily check for a certain sequence of tokens.
When an expression function is called it then calls a sequence of other expression functions in an attempt to find another match. The `primary_exp` function tries to match the next token to an integer, true, or false.

There are different types of statements. Declaration and Expression statements. 
