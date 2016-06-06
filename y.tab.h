/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WHILE = 258,
    IF = 259,
    TRUE = 260,
    FALSE = 261,
    INT = 262,
    FLOAT = 263,
    PC = 264,
    COMA = 265,
    ID = 266,
    NUM = 267,
    ASIG = 268,
    OR = 269,
    AND = 270,
    NE = 271,
    EQ = 272,
    GT = 273,
    GE = 274,
    LE = 275,
    LT = 276,
    PLUS = 277,
    MENUS = 278,
    MUL = 279,
    DIV = 280,
    MOD = 281,
    NOT = 282,
    LPAR = 283,
    RPAR = 284,
    LCOR = 285,
    RCOR = 286,
    IFX = 287,
    ELSE = 288
  };
#endif
/* Tokens.  */
#define WHILE 258
#define IF 259
#define TRUE 260
#define FALSE 261
#define INT 262
#define FLOAT 263
#define PC 264
#define COMA 265
#define ID 266
#define NUM 267
#define ASIG 268
#define OR 269
#define AND 270
#define NE 271
#define EQ 272
#define GT 273
#define GE 274
#define LE 275
#define LT 276
#define PLUS 277
#define MENUS 278
#define MUL 279
#define DIV 280
#define MOD 281
#define NOT 282
#define LPAR 283
#define RPAR 284
#define LCOR 285
#define RCOR 286
#define IFX 287
#define ELSE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 27 "parser.y" /* yacc.c:1909  */

	char id[100];

	struct{
		char code[1000];
		char dir[100];
	} exp;

	struct{
		char next[100];
		char code[1000];
	}sent;

	struct{
		char ltrue[100];
		char lfalse[100];
		char code[1000];
	}cond;

	struct{
		int type;
		char dir[100];
	}num;

	struct{
		int width;
		int type;
	}type;
	char op[3];


#line 152 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
