#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_ID 50
#define TAM_SYM_TABLE 100
#define TAM_PILA 10
#if 0
#include <string.h>
typedef struct SymbolTable Symbols;
typedef struct Tupla Tupla;
typedef struct Nodo Nodo;
struct Tupla
{
	char* str;
	int token;
};

struct Nodo
{
	Tupla tupla;
	Nodo* next;
};
struct SymbolTable
{
	Nodo* root;
	int num;
};
//definiciones de funciones que se emplean para crear la tabla de símbolos.

int insert_end(Symbols* symbols, char *str, int token);
Nodo* crea_nodo(char* str, int token);
int search(char* str, Symbols* symbols);
void init_symbols(Symbols *symbols);
Symbols* init(Symbols *symbols);
void print(Symbols* symbols);

#endif

/////////////////////////////////////////////////////////////77
int i;
int contSstack;
typedef struct _symbol_table Stable;
typedef struct _symbol symbol;
typedef struct _params params;
struct _params
{
	int type[20];
	int cont;
};
struct _symbol
{
	char id[TAM_ID];
	int type;
	int typeVar;
	int dir;
	params param;
};
int typeVar;
struct _symbol_table
{
	symbol s[TAM_SYM_TABLE];
	int cont;
};
Stable Sstack[TAM_PILA];

symbol create_symbol(char* id,int type,int typeVar,int dir, params param);
int insert_symbol(symbol s);
int get_Symbol(char* id,int table);
params create_param(int type,int cont);
params getParams(char* id);
void setParams(char* id,params p);
int getTypeSymbol(char* id,int table);
int getTypeVar(char* id,int table);
void push_symbol();
void pop_symbol();

symbol create_symbol(char* id,int type,int typeVar,int dir, params param)
{
	symbol tmp;
	strcpy(tmp.id,id);
	tmp.type=type;
	tmp.typeVar=typeVar;
	tmp.dir=dir;
	tmp.param=param;
	return tmp;
}

int insert_symbol(symbol s)
{
	int i;
	i=get_Symbol(Sstack[contSstack-1].s[Sstack[contSstack-1].cont].id,contSstack);
	if (i != -1 )
	{
		Sstack[contSstack-1].s[Sstack[contSstack-1].cont] = s;
		Sstack[contSstack-1].cont++;
		return Sstack[contSstack-1].cont-1;
	}
	return -1;
}

int get_Symbol(char* id,int table)
{
	for (i = 0; i < Sstack[table].cont; i++)
	{
		if (!strcmp(Sstack[table].s[i].id,id))
			return i;
	}
	return -1;
}

params create_param(int type,int cont)
{
	params tmp;
	/* In file included from proof.c:2:0:
		symboltable.h: In function ‘create_param’:
		symboltable.h:128:10: error: assignment to expression with array type
	  	tmp.type=&type;
          	^
 	*/
	tmp.type=type;
	tmp.cont=cont;
	return tmp;
}

params getParams(char* id)
{
	int i = get_Symbol(id,0);
	return Sstack[0].s[i].param;
}

void setParams(char* id,params p)
{
	int i=get_Symbol(id,0);
	Sstack[0].s[i].param=p;
}

int getTypeSymbol(char* id,int table)
{
	int i = get_Symbol(id,table);
	return Sstack[table].s[i].type;
}
int getTypeVar(char* id,int table)
{
	int i = get_Symbol(id,table);
	return Sstack[table].s[i].typeVar;
}
void push_symbol()
{
	contSstack++;
}
void pop_symbol()
{
	Sstack[contSstack-1].cont = 0;
	contSstack--;
}



#endif
