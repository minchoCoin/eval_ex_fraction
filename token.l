%{
    #include <stdlib.h>
    #include "ast.h"
    #include "y.tab.h"
    
%}

%%
-?[0-9]     { yylval.ival = atoi(yytext); return NUM; }

[ \t]   ;
\(  return ('(');
\)  return (')');
\n  return (0);
.   {printf("'%c': illegal character\n"),yytext[0]; exit(-1);}    
%%
int yywrap()    {return 1;}