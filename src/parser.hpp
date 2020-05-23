/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.ypp" /* yacc.c:1909  */

  #include "structures/Program.h"
  #include "structures/Pipeline.h"
  #include "structures/Node.h"
  #include "structures/Value.h"
  #include "structures/Command.h"
  #include "structures/Variable.h"
  #include "structures/VarPip.h"

  #include <iostream>
  #include <exception>
  #include <string>
  // #define DEBUG
  #define YYERROR_VERBOSE 1
  using namespace std;
  extern int yylex_destroy(void);
  int yylex(void);
  void set_input_string(const char* in);
  void end_lexical_scan(void);
  Program *parse(std::string);
  bool isEmpty(std::string);
  void parse_to_root(std::string);
  void find_bt_expressions(std::string);

#line 69 "parser.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    SC = 259,
    SM = 260,
    GR = 261,
    BT = 262,
    EOL = 263,
    EOFF = 264,
    OR = 265,
    EXPORT = 266,
    ERROR = 267,
    IGNORE = 268,
    STR = 269,
    BT_EXPRESSION = 270,
    DQ_EXPRESSION = 271,
    SQ_EXPRESSION = 272
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 36 "parser.ypp" /* yacc.c:1909  */

    char* sval;
    Command *command;
    Node *node;
    Pipeline *pipeline;
    Program *program;
    Value *value;
    Variable *variable;
    VarPip *varpip;

#line 110 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
