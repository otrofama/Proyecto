#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#define TAM_TTABLE 100

////////////////////////////////////

#if 0
typedef struct TypeTable Types;
typedef struct Tupla Tupla;
typedef struct Nodo Nodo;


struct Tupla
{
	char* str;
	int token;
};
struct Tupla
{
	int pos;
	int type;
	int dim;
	int bytes;
	int base;
};

struct Nodo
{
	Tupla tupla;
	Nodo* next;
};
struct Types
{
	Nodo* root;
	int num;
};
//definiciones de funciones que se emplean para crear la tabla de símbolos.

int insert_end(Types* types, char *str, int token);
Nodo* crea_nodo(char* str, int token);
int search(char* str, Types* types);
void init_types(Types *types);
Types* init(Types *types);
void print(Types* types);
/**
 * void error(char* msg);
 */

#endif

////////////////////////////////////
int contTstack;
typedef struct _type type;
typedef struct _type_table Ttable;

struct _type
{
	int type;
	int dim;
	int width;
	int base;
};

struct _type_table
{
	//type _type_table[TAM_TTABLE];
	type t[TAM_TTABLE];
	int cont;
};


type create_type(int type,int dim,int width,int base);
Ttable Tstack[TAM_TTABLE];
int insert_type(int table,type t);
int getWidthElement(int i,int table);
int getTypeBase(int i,int table);
void create_type_table(Ttable* table);
void push_type();
void pop_type();

int insert_type(int table,type t)
{
	Tstack[table].t[Tstack[table].cont]=t;
	Tstack[table].cont++;
	return Tstack[table].cont-1;
}

type create_type(int type1,int dim,int width,int base)
{
	type tmp;
	tmp.type=type1;
	tmp.dim=dim;
	tmp.width=width;
	tmp.base=base;
	return tmp;
}

void create_type_table(Ttable* table)
{
	//falta completar
	type t_char = create_type(0,-1,1,-1);
	type t_int = create_type(1,-1,4,-1);
	type t_float = create_type(2,-1,8,-1);
	type t_double = create_type(3,-1,16,-1);
	table->t[0]= t_char;
	table->t[1]= t_int;
	table->t[2]= t_float;
	table->t[3]= t_double;
	table->cont = 4;
}

void push_type()
{
	//create_type_table(Tstack[contTstack].cont);
	create_type_table(&Tstack[contTstack]);
	contTstack++;
}
void pop_type()
{
	Tstack[contTstack-1].cont=0;
	contTstack--;
}

int getTypeBase(int i,int table)
{
	return Tstack[table].t[i].base;
}

int getWidthElement(int i,int table)
{
	return Tstack[table].t[i].width;
}

#endif
