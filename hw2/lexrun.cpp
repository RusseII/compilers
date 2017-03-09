#include <iostream>
#include <string>
#include "lex.hpp"
#include <vector>
#include "ast.hpp"
using namespace std;

int main() {
    vector<Token*> tokens; //holds all of my tokens
    
    while (true) {
        string in;
        getline(cin, in);    
        if (in != "") {
           Lexer lex = Lexer(in);

            while(lex.first != lex.last){
               tokens.push_back(lex.next());
            }
               tokens.push_back(lex.next());

           for(int i = 0; i < tokens.size(); i++) {
               cout << "<" << tokens[i]->kind << "," << tokens[i]->att <<">  ";
           }
        }
    }
}
