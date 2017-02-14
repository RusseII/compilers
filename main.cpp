#include <iostream>
#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "typecheck.hpp"

int main() {
    Context cxt;
    {
    Expr* e =  new Or_expr( new Not_expr( new Bool_expr(true) ),
     new Bool_expr(true)
      );
    check(cxt,e);
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';

     e =  new And_expr( new Not_expr( new Bool_expr(true) ),
     new Bool_expr(true)
      );
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';

     e =  new GT_expr(  new Int_expr(333) ,
     new Int_expr(2)
      );
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';




  }






}
