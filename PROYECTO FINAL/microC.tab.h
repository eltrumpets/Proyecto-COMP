/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MICROC_TAB_H_INCLUDED
# define YY_YY_MICROC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 53 "microC.y"

    #include "listaCodigo.h"

#line 53 "microC.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PYC = 258,                     /* ";"  */
    IDE = 259,                     /* "identifier"  */
    IGU = 260,                     /* "="  */
    SUM = 261,                     /* "+"  */
    RES = 262,                     /* "-"  */
    COI = 263,                     /* "{"  */
    COD = 264,                     /* "}"  */
    PAI = 265,                     /* "("  */
    PAD = 266,                     /* ")"  */
    PRI = 267,                     /* "print"  */
    COM = 268,                     /* ","  */
    CAD = 269,                     /* "cadena"  */
    MUL = 270,                     /* "*"  */
    VOI = 271,                     /* "void"  */
    VAR = 272,                     /* "var"  */
    CON = 273,                     /* "const"  */
    INT = 274,                     /* "int"  */
    IFF = 275,                     /* "if"  */
    ELS = 276,                     /* "else"  */
    DO = 277,                      /* "do"  */
    WHI = 278,                     /* "while"  */
    REA = 279,                     /* "read"  */
    DIV = 280,                     /* "/"  */
    MNR = 281,                     /* "<"  */
    MYR = 282,                     /* ">"  */
    MNI = 283,                     /* "<="  */
    MYI = 284,                     /* ">="  */
    IG2 = 285,                     /* "=="  */
    DES = 286,                     /* "!="  */
    NUM = 287,                     /* "number"  */
    SIGNO = 288,                   /* SIGNO  */
    NOELSE = 289                   /* NOELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "microC.y"

  ListaC codigo;
  char *str;

#line 109 "microC.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MICROC_TAB_H_INCLUDED  */
