#ifndef TYPECHECK_HPP 
#define TYPECHECK_HPP
#include <iostream>
#include <cassert>
#include "ast.hpp"
#include "value.hpp"



Type* check(Context& cxt, Expr* e) {
    struct V : Expr::Visitor {
        Type* r;
        Context& cxt;

        V(Context& e) : cxt(e) { }

        void visit(Bool_expr* e) {
            r = &cxt.bool_type;
        }

        void visit(Not_expr* e) {
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


        void visit(Xor_expr* e) {//bool or int? check
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }

        void visit(Rem_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }

        void visit(Neg_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type);
            r = &cxt.int_type;
        }

    };
    V vis(cxt);
    e->accept(vis);
    return vis.r;
}    
#endif
