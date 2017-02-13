#include "ast.hpp"
#include "value.hpp"

Value eval(Expr* e) {
    
  struct V : Expr::Visitor {
    Value r;
    void visit(Int_expr * e) { r.data.n = e->val; r.kind = Value_kind::int_val; }
    void visit(Bool_expr* e) { r.data.b = e->val;  r.kind = Value_kind::bool_val; }
    void visit(And_expr* e) { r.data.b = eval(e->e1).data.b & eval(e->e2).data.b; r.kind = Value_kind::bool_val; }
    void visit(Or_expr* e) { r.data.b  = eval(e->e1).data.b | eval(e->e2).data.b; r.kind = Value_kind::bool_val; }
    void visit(Not_expr* e) { r.data.b = !eval(e->e1).data.b; r.kind = Value_kind::bool_val; }
    void visit(LT_expr* e) { r.data.n = eval(e->e1).data.n < eval(e->e2).data.n; r.kind = Value_kind::int_val; } 
    void visit(GT_expr* e) { r.data.n = eval(e->e1).data.n > eval(e->e2).data.n; r.kind = Value_kind::int_val; }
   // void visit(Eq_expr* e) { r.data.b = eval(e->e1).data.
   // void visit(NEq_expr* e)
    void visit(ELT_expr* e) { r.data.n = eval(e->e1).data.n <= eval(e->e2).data.n; r.kind = Value_kind::int_val; }
    void visit(EGT_expr* e) { r.data.n = eval(e->e1).data.n >= eval(e->e2).data.n; r.kind = Value_kind::int_val; }
    void visit(Add_expr* e) { r.data.n = eval(e->e1).data.n + eval(e->e2).data.n; r.kind = Value_kind::int_val; }
    void visit(Sub_expr* e) { r.data.n = eval(e->e1).data.n - eval(e->e2).data.n; r.kind = Value_kind::int_val; }
    void visit(Mul_expr* e) { r.data.n = eval(e->e1).data.n * eval(e->e2).data.n; r.kind = Value_kind::int_val; }
    void visit(Div_expr* e) { r.data.n = eval(e->e1).data.n / eval(e->e2).data.n; r.kind = Value_kind::int_val; }
    
    
    
  };
  V vis;
  e->accept(vis);
  return vis.r;




}
