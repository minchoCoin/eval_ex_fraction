 %{  #include <stdio.h>
#include <stdio.h>
#include "ast.h"
int yyerror(const char *msg), yylex();
Node *Root;
%}

%union {
int ival;
Node *pval;
}
%token <ival> NUM
%type <pval> Exp

%%
Prg : Exp { Root = $1; }
    ;

Exp : '(' Exp Exp Exp ')' { $$ = mkFractionNode($2,$3,$4);}
    | NUM {$$ = mkIntNode($1);}

%%
int main() { 
    yyparse();
    printTree(Root,0);
    Fraction result = evaluate(Root);
    printf("\n");
    printf("Answer: %d / %d\n",result.num, result.den);
}
int yyerror(const char *msg) { fputs(msg, stderr); return -1; }
