%{
#include <iostream>
#include "parser.hpp"

// #define YY_DECL extern "C" int yylex()
//#define DEBUG
using namespace std;
%}

%option noyywrap

%%
`[^`\n]+`                   {   yylval.sval = strdup(yytext);
                                #ifdef DEBUG
                                    cout << yylval.sval << endl;
                                #endif
                                return BT_EXPRESSION; }
"export"                    { return EXPORT; }
">"                         { return GR; }
"<"                         { return SM; }
"|"                         { return OR; }
"="                         { return ASSIGN; }
";"                         { return SC; }
[\._a-zA-Z][\._a-zA-Z0-9]*  { yylval.sval = strdup(yytext); return STR; }
<*>\n		                { BEGIN(INITIAL); return EOL; }
<*><<EOF>>	                { return EOFF; }
%%
void set_input_string(const char* in) {
  yy_scan_string(in);
}

void end_lexical_scan(void) {
  yy_delete_buffer(YY_CURRENT_BUFFER);
}
