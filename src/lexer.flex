%{
#include "parcer.tab.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include "src/structures/Identifier.h"
// #define DEBUG
using namespace std;
%}

%option noyywrap

%%
\$[_a-zA-Z][_a-zA-Z0-9]*    { 
                                yylval.sval = strdup(yytext); 
                            #ifdef DEBUG
                                cout << "MSG: " << yytext << endl;
                            #endif
                                return VARIABLE; 
                            }
"`"                     { return BT; }
">"                     { return GR; }
"<"                     { return SM; }
"&&"                    { return LAND; }
"||"                    { return LOR; }
"&"                     { return BAND; }
"|"                     { return BOR; }
"="                     { return ASSIGN; }
";"                     { return SC; }
[_a-zA-Z][_a-zA-Z0-9]*  { 
                            yylval.sval = strdup(yytext); 
                        #ifdef DEBUG
                            cout << "MSG: " << yytext << endl;
                        #endif
                            return IDENTIFIER; 
                        }
%%