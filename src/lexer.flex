%{
#include <iostream>
#include "parser.hpp"

// #define YY_DECL extern "C" int yylex()
//#define DEBUG
using namespace std;
%}

%option noyywrap
LETTER                      [\._\-a-zA-Z0-9\\\/]
%%
`[^`\n]+`                   {   yylval.sval = strdup(yytext);
                                #ifdef DEBUG
                                    cout << yylval.sval << endl;
                                #endif
                                return BT_EXPRESSION; }
\"[^\"\n]+\"                { yylval.sval = strdup(yytext);
                              return DQ_EXPRESSION; }
"export"                    { return EXPORT; }
">"                         { return GR; }
"<"                         { return SM; }
"|"                         { return OR; }
"="                         { return ASSIGN; }
";"                         { return SC; }
[\._\-a-zA-Z0-9\\\/$~][\._\-a-zA-Z0-9\\\/]*  { yylval.sval = strdup(yytext); return STR; }
[ \n\r\t\0]*                ;
[!@#%^&*()+=\'\[\]\(\)]              { return ERROR; }
%%
void set_input_string(const char* in) {
  yy_scan_string(in);
}

void end_lexical_scan(void) {
  yy_delete_buffer(YY_CURRENT_BUFFER);
}
