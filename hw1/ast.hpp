#ifndef AST_HPP
#define AST_HPP
#include <cassert>

struct Int_type;
struct Bool_type;

struct Bool_expr;
struct Int_expr;
struct Or_expr;
struct Not_expr;
struct And_expr;
struct LT_expr;
struct GT_expr;
struct Eq_expr;  //equal expression, opperants must be the same type: return in bool
struct NEq_expr; //not equal expression
struct ELT_expr; //Less or equal to expression
struct EGT_expr; //Greater or equal expression
struct Add_expr; //addition expression
struct Sub_expr; //subtraction expression
struct Mul_expr; //multiplication expression
struct Div_expr; //divison expression
struct Xor_expr; //Exclusive or expression
struct Rem_expr; //Division remaindor
struct Neg_expr; //Negate the expression
struct ITE_expr;  //if e1 then e2 else e2
struct T_expr; //e1 then e2 expression 
struct OE_expr; //e1 or else e2 expression

struct Type {
    struct Visitor;
    virtual ~Type() = default;
    virtual void accept(Visitor&) { }
};

struct Int_type : Type { }; 
struct Bool_type : Type { };

struct Expr {
    struct Visitor;
    virtual ~Expr() = default;
    virtual void accept(Visitor&) = 0; 
};

struct Expr::Visitor
{
    virtual void visit(And_expr*)= 0;
    virtual void visit(Or_expr*) = 0;
    virtual void visit(Bool_expr*) = 0;
    virtual void visit(Int_expr*) = 0;
    virtual void visit(Not_expr*) = 0;
    virtual void visit(LT_expr*) = 0;
    virtual void visit(GT_expr*) = 0;
    virtual void visit(Eq_expr*) = 0;
    virtual void visit(NEq_expr*) = 0;
    virtual void visit(ELT_expr*) = 0;
    virtual void visit(EGT_expr*) = 0;
    virtual void visit(Add_expr*) = 0;
    virtual void visit(Sub_expr*) = 0;
    virtual void visit(Mul_expr*) = 0;
    virtual void visit(Div_expr*) = 0;
    virtual void visit(Xor_expr*) = 0;
    virtual void visit(Rem_expr*) = 0;
    virtual void visit(Neg_expr*) = 0;
    virtual void visit(ITE_expr*) = 0;

};

struct And_expr: Expr {
    Expr* e1;
    Expr* e2;
    And_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Or_expr: Expr {
    Expr* e1;
    Expr* e2;
    Or_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Bool_expr : Expr {
    bool val;
    Bool_expr(bool b) : val(b) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Int_expr: Expr {
    int val;
    Int_expr(int b) : val(b) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Not_expr: Expr {
    Expr* e1;
    Not_expr(Expr* e1) : e1(e1) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct LT_expr: Expr {
    Expr* e1;
    Expr* e2;
    LT_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct GT_expr: Expr {
    Expr* e1;
    Expr* e2;
    GT_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Eq_expr: Expr {
    Expr* e1;
    Expr* e2;
    Eq_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct NEq_expr: Expr {
    Expr* e1;
    Expr* e2;
    NEq_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct ELT_expr: Expr {
    Expr* e1;
    Expr* e2;
    ELT_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct EGT_expr: Expr {
    Expr* e1;
    Expr* e2;
    EGT_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Add_expr: Expr {
    Expr* e1;
    Expr* e2;
    Add_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Sub_expr: Expr {
    Expr* e1;
    Expr* e2;
    Sub_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Mul_expr: Expr {
    Expr* e1;
    Expr* e2;
    Mul_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Div_expr: Expr {
    Expr* e1;
    Expr* e2;
    Div_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};
struct Xor_expr: Expr {
    Expr* e1;
    Expr* e2;
    Xor_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Rem_expr: Expr {
    Expr* e1;
    Expr* e2;
    Rem_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct Neg_expr: Expr {
    Expr* e1;
    Neg_expr(Expr* e1) : e1(e1) { }
    void accept(Visitor& v) { return v.visit(this); }
};

struct ITE_expr: Expr {
    Expr* e1;
    Expr* e2;
    Expr* e3;
    ITE_expr(Expr* e1, Expr* e2, Expr* e3) : e1(e1), e2(e2), e3(e3) { }
    void accept(Visitor& v) { return v.visit(this); }
};





struct Context
{
    Bool_type bool_type;
    Int_type int_type;
};

#endif
