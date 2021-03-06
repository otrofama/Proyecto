%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symboltable.h"
#include "typetable.h"
int t,w,c_t,c_w,offset=0;
int stackoffset[50];
int spoffset=0;
char label[100];
char temp[100];

void newTemp();
int cTemp;


void newLabel();
int cLabel;

void yyerror();

extern FILE *yyin;
extern int yylineno;

FILE *output;
int t;
int w;
%}

%union
{
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

}

%token WHILE IF
%token TRUE FALSE
%token INT FLOAT DOUBLE CHAR
%token PC COMA
%token DEFINE RETURN
%token<id> ID;
%token<num> NUM;

%left<op> ASIG MASIG MEASIG DIVASIG MULASIG MODASIG
%left OR
%left AND
%left<op> NE EQ
%left<op> GT GE LE LT
%left<op> PLUS MENUS
%left<op> MUL DIV MOD
%right NOT
%nonassoc LPAR RPAR LCOR RCOR RKEY LKEY
%nonassoc IFX
%nonassoc ELSE


%type<cond> boolean
%type<sent> sent sentp sents
%type<exp> exp term factor
%type<op> oprel opadd opmul opasig
%type<type> type base array

%start program

%%

program: {offset = 0;
		//push_symbol();
		//push_type();
		//}decl sents {
		}decl sents {
			strcat($3.code, "halt");
			fprintf(output,"%s",$3.code);
			//free($1.code);
			};

decl: decl type {c_w=$2.type; c_w=$2.width;} list_var PC |;


declf: declf DEFINE type ID LPAR fun RPAR LCOR sents RCOR | ;
//sents: sents DEFINE type ID LPAR fun RPAR LCOR sents RCOR | ;

fun: fun COMA type ID | type ID;


type: base {
	w=$1.width;
	t=$1.type;
	} array {
		$$.type=$3.type;
		$$.width=$3.width;
	};

base: INT {$$.type=1;$$.width=4;}
	| FLOAT {$$.type=2;$$.width=8;}
	| DOUBLE {$$.type=3;$$.width=16;}
	| CHAR {$$.type=0;$$.width=1;};

array: LCOR NUM RCOR array {
		//$$.type = insert_type("array", $4.type, atoi($2.dir));
		$$.width = atoi($2.dir) * $4.width;
		}
		| {$$.type = t; $$.width = w;};

list_var : list_var COMA ID | ID;

sents : sents sent {
				strcpy($$.code, $1.code);
				strcat($$.code, $2.code);
				strcat($$.code, $2.next);
				//strcat($$.code, ":");375
				strcat($$.code, ":");
			}
			| sent{
				//strcat($1.code, $1.next);
				strcat($$.code, $1.next);
				strcat($$.code, $1.code);
				strcat($1.code, ":");
			};

sent: WHILE LPAR boolean RPAR sent {
			strcpy($$.next, $3.lfalse);
			//int len = strlen($5.next)+1;
			//$$.code = (char*) malloc(len*sizeof(char));
			strcpy($$.code, $5.next);
			strcat($$.code, ": ");
			strcat($$.code, $3.code);
			strcat($$.code, $3.ltrue);
			strcat($$.code, ":");
			strcat($$.code, $5.code);
			strcat($$.code, "goto ");
			strcat($$.code, $5.next);
			strcat($$.code, "\n");
			//free($3.code);
			//free($5.code);
			//printf("goto %s\n",$1.begin);
    }
	| LKEY sents RKEY {
	//| LCOR L RCOR {
		strcpy($$.code,$2.next);
		strcpy($$.code,$2.code);
	}
	//| IF LPAR boolean RPAR sent {
	| IF LPAR boolean RPAR sent sentp {
		//strcpy($<sent>$.next, $3.lfalse);
		strcpy($$.code, $3.lfalse);
		strcat($$.code, $5.next);
		strcat($$.code, ":");
		strcpy($$.next, $5.next);
		strcat($$.next,$6.next);

		strcat($$.next,$3.code);
		strcpy($$.code,$3.ltrue);
		strcat($$.code, ":");
		strcat($$.code,$5.code);
		strcat($$.code, "goto");
		strcat($$.code,$6.code);

	}

	| idef opasig exp PC {
		newLabel(); strcpy($$.code,label);
		newLabel(); strcpy($$.code,label);
	}
	|RETURN exp PC{
		newLabel();
		strcpy($$.code,label);
		newLabel();
		strcpy($$.code,label);
		strcpy($$.code,$2.code);
		strcpy($$.code,"return ");
		strcat($$.code,$2.dir);
		strcat($$.code,"\n");

		};

sentp: ELSE sent {
					strcpy($$.next, $2.next);

					strcpy($$.code, "goto ");
					strcat($$.code, $2.next);
					strcat($$.code, "\n");
					strcat($$.code, $<sent>0.next);
					strcat($$.code, ":");
					strcat($$.code, $2.code);
				}
				|	{
					strcpy($$.next,"");
					strcpy($$.code,$<sent>0.next);
					strcpy($$.code,":");
				};

			//|
			/*%prec IFX {
					strcpy($$.next, "");
					strcpy($$.code, $<sent>0.next);
					strcat($$.code, ":");
				}*/;
idef: axp| ID ;

boolean : boolean OR boolean
			{
				strcpy($$.ltrue, $1.ltrue);
				strcat($$.ltrue, ":");
				strcat($$.ltrue, $3.ltrue);

				strcpy($$.lfalse, $3.lfalse);
				//int len = strlen($1.code) +1;
				//$$.code = (char*) malloc(len*sizeof(char));
				strcpy($$.code, $1.code);
				strcat($$.code, $1.lfalse);
				strcat($$.code, ": ");
				strcat($$.code, $3.code);
				//free($1.code);
				//free($3.code);
			}
		| boolean AND boolean
			{
				strcpy($$.lfalse, $1.lfalse);
				strcat($$.lfalse, ":");
				strcat($$.lfalse, $3.lfalse);

				strcpy($$.ltrue, $3.ltrue);
				//int len = strlen($1.code) +1;
				//$$.code = (char*) malloc(len*sizeof(char));
				strcpy($$.code, $1.code);
				strcat($$.code, $1.ltrue);
				strcat($$.code, ": ");
				strcat($$.code, $3.code);
				//free($1.code);
				//free($3.code);
			}
		| NOT boolean {
				strcpy($$.ltrue, $2.lfalse);
				strcpy($$.lfalse, $2.ltrue);
				strcpy($$.code, $2.code);
			}
		| LPAR boolean RPAR {
				strcpy($$.ltrue, $2.ltrue);
				strcpy($$.lfalse, $2.lfalse);
				strcpy($$.code, $2.code);
		}
		| TRUE {
				newLabel();		strcpy($$.ltrue, label);
				newLabel();		strcpy($$.lfalse, label);
				strcpy($$.code, "goto ");
				strcat($$.code, $$.ltrue);
				strcat($$.code, "\n");
			}
		| FALSE{
				newLabel();		strcpy($$.ltrue, label);
				newLabel();		strcpy($$.lfalse, label);
				strcpy($$.code, "goto ");
				strcat($$.code, $$.lfalse);
				strcat($$.code, "\n");
		}
		| exp oprel exp{
				newLabel();		strcpy($$.ltrue, label);
				newLabel();		strcpy($$.lfalse, label);
				strcpy($$.code, $1.code);
				strcat($$.code, $3.code);
				strcat($$.code, "if ");
				strcat($$.code, $1.dir);
				strcat($$.code, $2);
				strcat($$.code, $3.dir);
				strcat($$.code, " goto ");
				strcat($$.code, $$.ltrue);
				strcat($$.code, "\n");
				strcat($$.code, "goto ");
				strcat($$.code, $$.lfalse);
				strcat($$.code, "\n");
		};

opasig: ASIG
		| MASIG
		| MEASIG
		| DIVASIG
		| MULASIG
		| MODASIG



oprel : GT { strcpy($$, $1);}
		| GE { strcpy($$, $1);}
		| LT { strcpy($$, $1);}
		| LE { strcpy($$, $1);}
		| NE { strcpy($$, $1);}
		| EQ { strcpy($$, $1);};

exp : exp opadd term {
				newTemp();
				strcpy($$.dir, temp);

				strcpy($$.code, $1.code);
				strcat($$.code, $3.code);
				strcat($$.code, $$.dir);
				strcat($$.code, " = ");
				strcat($$.code, $1.dir);
				strcat($$.code, " ");
				strcat($$.code, $2);
				strcat($$.code, " ");
				strcat($$.code, $3.dir);
				strcat($$.code, "\n");
			}
			| term{
				$$ = $1;
			};

term: term opmul factor{
				newTemp();
				strcpy($$.dir, temp);

				strcpy($$.code, $1.code);
				strcat($$.code, $3.code);
				strcat($$.code, $$.dir);
				strcat($$.code, " = ");
				strcat($$.code, $1.dir);
				strcat($$.code, " ");
				strcat($$.code, $2);
				strcat($$.code, " ");
				strcat($$.code, $3.dir);
				strcat($$.code, "\n");
			}
			| factor{
				$$= $1;};
			//| axp
			//| af
			//| ID LPAR af RPAR;

factor: LPAR exp RPAR {$$ = $2;}
		|ID {
			strcpy($$.dir, $1);
			strcpy($$.code, "");
		}
		| NUM {
			strcpy($$.dir, $1.dir);
			strcpy($$.code, "");
		}|af
		|axp;

af: af COMA exp | exp;


axp: ID LCOR exp RCOR| axp LCOR exp RCOR;


opadd: PLUS { strcpy($$, $1);}
		| MENUS { strcpy($$, $1);};

opmul: MUL { strcpy($$, $1);}
		| DIV { strcpy($$, $1);}
		| MOD { strcpy($$, $1);};
%%

void newLabel(){
	cLabel++;
	char num[50];
	sprintf(num, "%d", cLabel);
	strcpy(label,"l");
	strcat(label,num);
}

void newTemp(){
	cTemp++;
	char num[50];
	sprintf(num, "%d", cTemp);
	strcpy(temp,"t");
	strcat(temp,num);
}

void yyerror(){
	printf("error sintactico en la línea %d\n", yylineno);
}


int main(int argc, char** argv)
{
	FILE *file;
	//char name[100];
	char* name;

	if(argc >1)
	{
		file = fopen(argv[1], "r");
		if(!file)
		{
			printf("No se pudo abrir el archivo\n");
			exit(0);
		}
		name = (char*)malloc(2*sizeof(char));
		strcpy(name, argv[1]);
		strcat(name, ".ci");
		output = fopen(name,"w");
		yyin = file;
		yyparse();
		fclose(output);
		fclose(yyin);
	}
	else
	{
		printf("No se ingresó archivo.");
	}

	return 0;
}
