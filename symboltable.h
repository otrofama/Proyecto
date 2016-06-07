
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
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
struct _symbol
{
	char id[TAM_ID];
	int type;
	int typeVar;
	int dir;
	params param;
}
typedef struct _symbol symbol;
struct _symbol_table
{
	symbol s[TAM_SYM_TABLE];
	int cont;
};
typedef struct _symbol_table Stable;
Stable Sstack[TAM_PILA];
int contSstack;

int insert_symbol(symbol s)
{
	int i = get_Symbol(Sstack[contTstack-1].s[Sstack[contTstack-1].cont],contSstack);
	if (i != -1 )
	{
		Sstack[contTstack-1].s[Sstack[contTstack-1].cont] = s;
		Sstack[contTstack-1].cont++;
		return Sstack[contSstack-1].cont-1;
	}
	return -1;
}
#endif
