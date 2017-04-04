#include <iostream>
#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "typecheck.hpp"

int main() {
     Context cxt;
     {
     Expr* e = new Or_expr(new Not_expr(new Bool_expr(true)), new Bool_expr(true));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.b << '\n';
 
     e =  new And_expr(new Not_expr( new Bool_expr(true)) ,new Bool_expr(true));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.b << '\n';

     e =  new GT_expr(new Int_expr(333), new Int_expr(2));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.b << '\n';

     e =  new LT_expr(new Int_expr(333), new Int_expr(2));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.b << '\n';


     e =  new EGT_expr(new Int_expr(333), new Int_expr(2));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.b << '\n';


     e =  new ELT_expr(new Int_expr(333), new Int_expr(2));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.b << '\n';


     e =  new Mul_expr(new Int_expr(333), new Int_expr(2));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.n << '\n';


     e =  new Div_expr(new Int_expr(333), new Int_expr(2));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.n << '\n';


     e =  new Rem_expr(new Int_expr(333), new Int_expr(2));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.n << '\n';

   
     e =  new Xor_expr(new Not_expr( new Bool_expr(true)) ,new Bool_expr(true));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.b << '\n';

     e =  new Sub_expr(new Int_expr(333), new Int_expr(2));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.n << '\n';


     e =  new Add_expr(new Int_expr(333), new Int_expr(2));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.n << '\n';

     e =  new ITE_expr(new Bool_expr(true), new Bool_expr(false), new Bool_expr(true));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.n << '\n';


     e =  new Eq_expr( new Bool_expr(false), new Bool_expr(true));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.n << '\n';


     e =  new NEq_expr( new Bool_expr(false), new Bool_expr(true));
     check(cxt,e);
     print(e);
     std::cout << " == " << eval(e).data.n << '\n';






  }






}
