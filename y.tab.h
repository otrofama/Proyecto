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
    DOUBLE = 264,
    CHAR = 265,
    PC = 266,
    COMA = 267,
    DEFINE = 268,
    RETURN = 269,
    ID = 270,
    NUM = 271,
    ASIG = 272,
    MASIG = 273,
    MEASIG = 274,
    DIVASIG = 275,
    MULASIG = 276,
    MODASIG = 277,
    OR = 278,
    AND = 279,
    NE = 280,
    EQ = 281,
    GT = 282,
    GE = 283,
    LE = 284,
    LT = 285,
    PLUS = 286,
    MENUS = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    NOT = 291,
    LPAR = 292,
    RPAR = 293,
    LCOR = 294,
    RCOR = 295,
    RKEY = 296,
    LKEY = 297,
    IFX = 298,
    ELSE = 299
  };
#endif
/* Tokens.  */
#define WHILE 258
#define IF 259
#define TRUE 260
#define FALSE 261
#define INT 262
#define FLOAT 263
#define DOUBLE 264
#define CHAR 265
#define PC 266
#define COMA 267
#define DEFINE 268
#define RETURN 269
#define ID 270
#define NUM 271
#define ASIG 272
#define MASIG 273
#define MEASIG 274
#define DIVASIG 275
#define MULASIG 276
#define MODASIG 277
#define OR 278
#define AND 279
#define NE 280
#define EQ 281
#define GT 282
#define GE 283
#define LE 284
#define LT 285
#define PLUS 286
#define MENUS 287
#define MUL 288
#define DIV 289
#define MOD 290
#define NOT 291
#define LPAR 292
#define RPAR 293
#define LCOR 294
#define RCOR 295
#define RKEY 296
#define LKEY 297
#define IFX 298
#define ELSE 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 32 "parser.y" /* yacc.c:1909  */

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


#line 174 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
