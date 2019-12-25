%{
  #include <bits/stdc++.h>
  #include "ASTDeclaration.h"
  #include <iostream>
  extern "C" int yylex();
  extern "C" int yyparse();
  extern "C" FILE *yyin;
  extern "C" int errors;
  void yyerror (char const *s);
  int errors = 0;
  using namespace std;
%}
// %start program
// %token <val> IDENTIFIER STRING
// %token <num> NUMBER
// %token WHILE GOT IF ELSE
// %token PRINT READ RETURN
// %token FOR PRINTLN
// %token SC COMMA COLON
// %token OP CP OSB CSB ORB CRB
// %token <val> AND OR NOT INT
// %token <val> ADD SUB MUL DIV MOD
// %token <val> GT LT LE GE
// %token <val> EQ NOTEQUALS
// %token <val> EQUALS

// %left EQUALS NOTEQUALS
// %left AND OR
// %left LT GT
// %left LE GE
// %left ADD SUB
// %left MUL DIV MOD
// %nonassoc NOT

// %type <statements> program
// %type <statements> program_stmts
// %type <functionDeclaration> func_decl
// %type <variableDeclarations> func_decl_args
// %type <expressions> func_call_args
// %type <functionCall> func_call
// %type <variableDeclaration> var_decl
// %type <val> type
// %type <statements> stmts
// %type <identifier> ident
// %type <expression> expr
// %type <assignmentStmt> assign_stmt
// %type <forStmt> for_stmt
// %type <ifElseStmt> if_stmt
// %type <whileStmt> while_stmt
// %type <printStmt> print_stmt
// %type <readStmt> read_stmt
// %type <returnStmt> return_stmt
// %type <block> block
// Tokens
%union {
  char *sval;
}

%start commandset


%token LAND LOR BAND BOR
%token ASSIGN SC EXPORT
%token <sval> SQ_LITERAL DQ_LITERAL BS_LITERAL
%token <sval> IDENTIFIER VARIABLE

%%
program     : commandset {}
commandset  : /* blank */ {  }
            | command {  }
            | commandset ; command {  }
            ;

command     : /* blank */ {}
            | expression {}
            | pipeline {}
            | IDENTIFIER=IDENTIFIER {}
            | IDENTIFIER=VARIABLE {}
            | EXPORT IDENTIFIER=IDENTIFIER {}
            | EXPORT IDENTIFIER=VARIABLE {}
            | command && command {}
            | command || command {}
            ;

pipeline    : pipeline | expression {}
            | expression | expression {}
            ;

// Add assignment expressions (VARIABLES)
expression  : IDENTIFIER {}
            | literal {}
            | expression IDENTIFIER {}
            | expression literal {}
            | expression > IDENTIFIER {}
            | expression < IDENTIFIER {}
            ;

literal     : SQ_LITERAL {}
            | DQ_LITERAL {}
            | BS_LITERAL {}
            ;
%%

void yyerror (char const *s)
{
    errors++;
	  printf("Error: %s\n", s);
}

int main(int argc, char *argv[])
{
    if (argc == 1 ) {
		    fprintf(stderr, "Correct usage: xlang filename\n");
		    exit(1);
    }

  	if (argc > 2) {
  		  fprintf(stderr, "Passing more arguments than necessary.\n");
  		  fprintf(stderr, "Correct usage: xlang filename\n");
  	}

  	yyin = fopen(argv[1], "r");

  	if (yyin == NULL){
  		  printf("Can't open the given file!\n");
  		  exit(-1);
  	}

  	do {
  		  yyparse();
  	} while (!feof(yyin));

  	if (root) {
  		generateCode(root);
  	}

  	return 0;
}
