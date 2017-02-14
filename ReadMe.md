# A Simple Compiler
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


## Implementation
The language supports two different types. Integers and Boolean values.  
Inside the `ast.hpp` file there is a struct `Type` that contains a struct `Visitor` and has a virtual member function `accept`.
This member function is used for passing around a `Visitor` object for preforming operations.

The two types, `Int_type` and `Bool_type` are subclasses of `Type`. 

There is a struct `Expr` which contains a struct `Visitor` and a pure virtual function `accept`. All of the operations inherit from `Expr` 

`Expr::Visitor` declares all of the pure virtual functions for the operations that the language can handle.
The rest of the file creates structs defining member variables and constructors for the operations.  

Inside the `eval.hpp` file there is a struct `V` which inherits from `Expr::Visitor`. It contains a `Value` object `r` which contains the expression's return type along with the data returned.


