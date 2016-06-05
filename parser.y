%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typetable.h"

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

%union{

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
%token INT FLOAT
%token PC COMA
%token<id> ID;
%token<num> NUM;

%left ASIG
%left OR
%left AND
%left<op> NE EQ
%left<op> GT GE LE LT
%left<op> PLUS MENUS
%left<op> MUL DIV MOD
%right NOT
%nonassoc LPAR RPAR LCOR RCOR
%nonassoc IFX  
%nonassoc ELSE  


%type<cond> boolean
%type<sent> sent sentp sents
%type<exp> exp term factor
%type<op> oprel opadd opmul
%type<type> base array

%start program

%%

program: decl sents {	
					strcat($2.code, "halt");				
					fprintf(output,"%s",$2.code);
					//free($1.code);
			};


decl: decl type list_var PC | ;


type: base{t = $1.type; w = $1.width;} array;

base: INT {$$.type = 0; $$.width = 4;}
		  | FLOAT {$$.type = 1; $$.width = 8;};

array: LCOR NUM RCOR array { 
				$$.type = insert_type("array", $4.type, atoi($2.dir));
				$$.width = atoi($2.dir) * $4.width;
			}
		| {$$.type = t; $$.width = w;};

list_var : list_var COMA ID | ID;

sents : sents sent {
				strcpy($$.code, $1.code);
				strcat($$.code, $2.code);
				strcat($$.code, $2.next);
				strcat($$.code, ":");				
			}
			| sent{
				strcat($1.code, $1.next);
				strcat($1.code, ":");			
			};

sent: ID ASIG exp PC { newLabel(); strcpy($$.next,label);
											 //int len = strlen($1) +1; 
											 //$$.code = (char*) malloc(len*sizeof(char));
											 strcpy($$.code, $3.code);
											 strcat($$.code, $1);
											 strcat($$.code, " = ");
											 strcat($$.code, $3.dir);
											 strcat($$.code, "\n");
											 
										}
		/* $1   $2   $3     $4   $5*/
	| WHILE LPAR boolean RPAR sent {			
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
	| IF LPAR boolean RPAR sent { strcpy($<sent>$.next, $3.lfalse);} sentp
		{
			strcpy($$.next, $5.next);
			strcat($$.next, ":");
			strcat($$.next, $7.next);

			strcpy($$.code, $3.code);
			strcat($$.code, $3.ltrue);
			strcat($$.code, ":");
			strcat($$.code, $5.code);
			strcat($$.code, $7.code);			
		}

		
;


sentp: ELSE sent {
					strcpy($$.next, $2.next);
				
					strcpy($$.code, "goto ");
					strcat($$.code, $2.next);
					strcat($$.code, "\n");
					strcat($$.code, $<sent>0.next);
					strcat($$.code, ":");
					strcat($$.code, $2.code);
				}

			| %prec IFX {
					strcpy($$.next, "");
					strcpy($$.code, $<sent>0.next);
					strcat($$.code, ":");					
				};

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
		}	
;


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
				$$= $1;
			};

factor: LPAR exp RPAR {$$ = $2;}
		|ID {
			strcpy($$.dir, $1);
			strcpy($$.code, "");
		}
		| NUM {
			strcpy($$.dir, $1.dir);
			strcpy($$.code, "");
		};

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


int main(int argc, char** argv){
	FILE *file;
	char name[100];

	if(argc >1){
		file = fopen(argv[1], "r");
		if(!file){
			printf("No se pudo abrir el archivo\n");
			exit(0);
		}
		strcpy(name, argv[1]);
		strcat(name, ".ci");
		output = fopen(name,"w");
		yyin = file;
	}


	yyparse();
	fclose(output);
	fclose(yyin);
	return 0;
}
