%{
#include "ASTDeclaration.h"
#include "parser.hpp"
#include <bits/stdc++.h>

#define YY_DECL extern "C" int yylex()

extern union Node yylval;
using namespace std;
%}

%%
\'.*\'                  { yylval.val = strdup(yytext); return SQ_LITERAL; }
\".*\"                  { yylval.val = strdup(yytext); return DQ_LITERAL; }
\`.*\`                  { yylval.val = strdup(yytext); return BS_LITERAL; }
\$[a-zA-Z][a-zA-Z0-9]   { yylval.val = strdup(yytext); return VARIABLE; }
&&                      { return LAND; }
||                      { return LOR; }
&                       { return BAND; }
|                       { return BOR; }
=                       { return ASSIGN; }
;                       { return SC; }
export                  { return EXPORT; }
[a-zA-Z][a-zA-Z0-9]*    { yylval.val = strdup(yytext); return IDENTIFIER; }

%%