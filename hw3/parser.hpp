#pragma once

#include <iostream>
#include "lex.hpp"
#include <vector>
#include "ast.hpp"
#include <sstream>
#include "statement.hpp"
#include <deque>

struct Parser {
    deque<Token*> tokens;
    
    Parser(deque<Token*> tokens): tokens(tokens)  {}

    Token* consume() {
        assert (!tokens.empty()); 
        Token* tok = tokens.front();
        tokens.pop_front(); 

        return tok;
    }

    Token* peek() {
        if (!tokens.empty())
            return tokens.front();
        else
            return nullptr;
    }

    Token_kind lookahead() {
        if (peek()!=nullptr) {
            Token* tok = peek();
            return tok->kind;
        }
       // else
        //    return Eof_token;
    }

    Token* match(Token_kind k) {
        if (lookahead() == k) {
            return consume();
        }
    }
};
    





