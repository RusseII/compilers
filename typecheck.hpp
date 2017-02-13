#ifndef TYPECHECK_HPP
#define TYPECHECK_HPP
#include <iostream>
#include <cassert>
#include "ast.hpp"


void 

Type* check(Contex& cxt, Expr* e) {
    struct V : Expr::Visitor {
        Type* r;
        Contex & cxt;

        V(Contex& e) : ctx(e) { }

        void visit(Bool_expr* e) {
            r = &cxt.bool_type;
        }

        void visit(Int_expr* e) {
            r = &cxt.int_type;
        }

        void visit(And_expr* e) {
            assert(check(cxt, e->e1) == &cxt.bool_type && check(cxt, e->e2) == &cxt.bool_type);
            r = &cxt.bool_type;
        }
   
         void visit(Or_expr* e) {
            assert(check(cxt, e->e1) == &cxt.bool_type && check(cxt, e->e2) == &cxt.bool_type);
            r = &cxt.bool_type;
        }
    
        void visit(LT_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }

        void visit(GT_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }

    
        void visit(ELT_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }
    
    
        void visit(EGT_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }
 
        void visit(Add_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }
        
        void visit(Sub_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }

        void visit(Mul_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }

        void visit(Div_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }
        

 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
}
