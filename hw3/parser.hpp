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


    Expr* add_exp() {
        Expr* e1= mul_exp();
        while (true) {
            if (match(Add_token)) {
                Expr* e2 = mul_exp(); //define this
                e1 = new Add_expr(e1,e2);
             }
            else if (match(Sub_token)) {
                Expr* e2 = mul_exp(); //define this
                e1 = new Sub_expr(e1,e2);
            }
            else
                break;
        }
        return e1;
    }

    Expr* mul_exp() {
        Expr* e1= unary_exp();
        while (true) {
            if (match(Mul_token)) {
                Expr* e2 = mul_exp(); //define this
                e1 = new Mul_expr(e1,e2);
             }
            else if (match(Div_token)) {
                Expr* e2 = mul_exp(); //define this
                e1 = new Div_expr(e1,e2);
            }
            else if (match(Mod_token)) {
                Expr* e2 = mul_exp(); //define this
                e1 = new Rem_expr(e1,e2);
            }
            else
                break;
        }
        return e1;
    }
    
    Expr* unary_exp() {
        if (match(Neg_token)) {
            Expr* e = unary_exp();
            return new Neg_expr(e);
        }
        else {
            return primary_exp();
        }
    }

    Expr* primary_exp() {
    }


};
    





