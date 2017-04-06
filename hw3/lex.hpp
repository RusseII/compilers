#ifndef LEX_HPP
#define LEX_HPP
#include <string>
#include <iostream>
using namespace std;

enum Token_kind { //used to represent the token_kind
    Bit_token,
    Xor_token, 
    Comment_token,
    LT_token,
    True_token,
    False_token,
    GT_token,
    Add_token,
    Sub_token,
    Mul_token,
    Div_token,
    ELT_token,
    Int_token,
    Bool_token,
    Mod_token,
    And_token,
    Or_token,
    RP_token,
    LP_token,
    Neg_token,
    EGT_token,
    Eq_token,
    Not_token,
    If_token,
    Then_token,
    Space_token,
    Semi_token
};

//represents a token, we eventually will build a vector of tokens
struct Token { 
    Token_kind kind;
    int att;
    Token(Token_kind t, int n)
        :kind(t), att(n) {}
    virtual ~Token() = default;
};

//defines the functions for lexing input
struct Lexer { 
    const char* first; //will point to begining of string so we can iterate through it
    const char* last;

    // built a sequence of characters. Used for integeres like 22
    // since 2 + 2 = 4 (we want it to be 22)
    string chars;

    Lexer(string s)
    :first(&s[0]), last(&s[s.length()-1]) {}
    
    //consume is used to add the next char to chars, and move to the next character in the string
    void consume(bool r = false) {
        if (r == false) {
            chars="";       
            *first++;
        }
        else {
            chars += *first++;
        } 
    }

   //used to peak at the current character - important in case statment to check if character matches operator
    char lookahead() const {
        return *first;
    }
    
    Token *next(); //seperation so that next can be defined outside this class 
};

//checks the string creates tokens for each operator or number
Token *Lexer::next() {
    switch(lookahead()) {

        case ' ': consume();
                  return new Token(Space_token, 0);

        case '#': consume();
                  return new Token(Comment_token, 0);

        case '<': consume();
            if (lookahead() == '=') {
                consume(); 
                return new Token(ELT_token, 0);
            }     
            return new Token(LT_token,0);

        case '>': consume();
                  if (lookahead() == '=') {
                      consume();
                      return new Token(EGT_token, 0);
                  }
                  return new Token(GT_token, 0);

        case '|': consume();
                  if(lookahead() == '|') {
                      consume();
                      return new Token(Or_token, 0);
                  }
                  else {
                      cerr<< "ERROR";
                  }
                  
        case '!': consume();
                  if (lookahead() == '='){
                      consume();
                      return new Token(Neg_token, 0);
                  } else {
                      return new Token(Not_token, 0);
                  }

        case '=': consume();
                  if (lookahead() == '='){
                      consume();
                      return new Token(Eq_token, 0);
                  } else {
                      cerr << "ERROR!";
                  }

        case '/': consume();
                  return new Token(Div_token, 0);

        case '(': consume();
                  return new Token(RP_token, 0);
                  
        case ')': consume();
                  return new Token(LP_token, 0);

        case '+': consume();
                  return new Token(Add_token, 0);
                  
        case '*': consume();
                  return new Token(Mul_token, 0);

        case '%': consume();
                  return new Token(Mod_token, 0);

        case '-': consume();
                  return new Token(Sub_token, 0);

        case '?': consume();
                      return new Token(If_token, 0);

        case ';': consume();
                      return new Token(Semi_token, 0);

        case ':': consume();
                      return new Token(Then_token, 0);

        case '&': consume();
                  if (lookahead() == '&') {
                      consume();
                      return new Token(And_token, 0);
                  }
                  else {
                      cerr<<"ERROR";
                  }
        case 't': consume();
                  if (lookahead() == 'r') {
                      consume();
                      if (lookahead() == 'u') {
                         consume();
                         if (lookahead() == 'e') {
                             consume();
                             return new Token(True_token,0);
                         }
                      }
                  }
                  else {
                     cerr<<"ERROR";
                  } 

        case 'f': consume();
                  if (lookahead() == 'a') {
                      consume();
                      if (lookahead() == 'l') {
                         consume();
                         if (lookahead() == 's') {
                            consume();
                            if (lookahead() == 'e') {
                                consume();
                             return new Token(False_token,0);
                            }
                         }
                      }
                  }
                  else {
                     cerr<<"ERROR";
                  } 


        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': consume(true);
                       while(first!=last and isdigit(lookahead())) { //build the int
                           consume(true);
                       }
                       return new Token(Int_token, stoi(chars));

    }
}
#endif
