%{
#include "structures/RedirectionExpr.h"
#include "structures/VariableAssignment.h"
#include "structures/VariableCall.h"
#include "structures/Program.h"
#include "structures/PipeExpr.h"
#include "structures/Node.h"
#include "structures/Identifier.h"
#include "structures/Command.h"
#include "structures/BackTickExpr.h"
#include <iostream>
#include "parser.hpp"

// #define YY_DECL extern "C" int yylex()
//#define DEBUG
using namespace std;
%}

%option noyywrap

%%
\$[_a-zA-Z][_a-zA-Z0-9]*    { yylval.sval = strdup(yytext+1); return VARIABLE; }
"\`"                         { return BT; }
">"                         { return GR; }
"<"                         { return SM; }
"&&"                        { return LAND; }
"||"                        { return LOR; }
"&"                         { return BAND; }
"|"                         { return BOR; }
"="                         { return ASSIGN; }
";"                         { return SC; }
[\._a-zA-Z][\._a-zA-Z0-9]*  { yylval.sval = strdup(yytext); return IDENTIFIER; }
<*>\n		                { BEGIN(INITIAL); return EOL; }
<*><<EOF>>	                { return EOFF; }
%%
void set_input_string(const char* in) {
  yy_scan_string(in);
}

void end_lexical_scan(void) {
  yy_delete_buffer(YY_CURRENT_BUFFER);
}
// "\`[^\`]*\`"           { yylval.sval = strdup(yytext); return BT_EXPRESSION; }