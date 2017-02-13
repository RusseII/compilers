#include <iostream>
#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"

int main() {
    Context cxt;
    {
    Expr* e =  new Or_expr( new Not_expr( new Bool_expr(true) ),
     new Bool_expr(true)
      );
    print(e);
    std::cout << " == " << eval(e).data.b << '\n';
  }






}
