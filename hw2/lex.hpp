#ifndef LEX_HPP
#define LEX_HPP
#include <string>
#include <iostream>
using namespace std;

enum Token_kind {
    Eof_token,   
    LT_token,
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
    Neq_token,
    EGT_token,
    Eq_token,
    Not_token,
    If_token,
    Then_token
};

struct Token{
    int kind;
    int att;
    Token(Token_kind t, int n)
        :kind(t), att(n) {}
    virtual ~Token() = default;
};

struct Lexer {
    const char* first;
    const char* last;
    
    string chars;

    Lexer() {}

    Lexer(string s)
    :first(&s[0]), last(&s[s.length()-1]) {}

    bool eof() const {
    return first == last;
    }
    
    char lookahead() const {
        return *first;
    }

    void consume() {
        //cout<<*first;
        chars += *first++;
    }
    
    Token *next(); //seperation  
};

Token *Lexer::next() {
    if (lookahead()==' ') {
        consume();
    }
    switch(lookahead()) {
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
                      return new Token(Neq_token, 0);
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
                  consume();
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
        case ' ': cerr<<"ERR";
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': consume();
                       while(!eof() && isdigit(lookahead())) { //build the int
                           consume();
                       }
                       return new Token(Int_token, stoi(chars));



    }
}
#endif
