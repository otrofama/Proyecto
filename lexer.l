%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "symboltable.h"
#include <string.h>
//Symbols* symbols;

%}

%option yylineno

digito [0-9]

%%

"("	{ return LPAR; }
")"	{ return RPAR; }
";"	{ return PC; }
"," { return COMA; }
while { return WHILE; }
if	{ return IF; }
else	{ return ELSE; }

			/* Operadores logicos */
"||" { strcpy(yylval.op, yytext); return OR; }
"&&"	{ strcpy(yylval.op, yytext); return AND; }
"!"		{ strcpy(yylval.op, yytext); return NOT; }

     /* Operadores relacionales */
"=" {	strcpy(yylval.op, yytext); return ASIG; }
">"	{ strcpy(yylval.op, yytext); return GT; }
"<"	{ strcpy(yylval.op, yytext); return LT; }
">=" { strcpy(yylval.op, yytext); return GE; }
"<=" { strcpy(yylval.op, yytext); return LE; }
"=="	{ strcpy(yylval.op, yytext); return EQ; }
"!="	{ strcpy(yylval.op, yytext); return NE; }

		/* Operadores aritmeticos */
"+" {	strcpy(yylval.op, yytext); return PLUS; }
"-"	{ strcpy(yylval.op, yytext); return MENUS; }
"*"	{ strcpy(yylval.op, yytext); return MUL; }
"/" { strcpy(yylval.op, yytext); return DIV; }
"%" { strcpy(yylval.op, yytext); return MOD; }

	/* Palabras reservadas */
int 	{ return INT; }
float	{ return FLOAT; }
char	{return CHAR; }
double 	{return DOUBLE; }
define	{return DEFINE;}



{digito}+	{
		  yylval.num.type = 0;
		  strcpy(yylval.num.dir, yytext);
 		  return NUM;
		}

[a-zA-Z_][a-zA-Z0-9_]*	{
			  strcpy(yylval.id, yytext);
			  return ID;
			}

"\n"	{ }

[ \t\r]	{}

.	{ printf("Error Léxico: %s, en la linea %d\n",yytext, yylineno);}

%%

int yywrap()
{
    return 1;
}
