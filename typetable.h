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
//int insert_type(Ttable* table,type t);
int insert_type(Ttable table,type t);
int getWidthElement(int i);
//void create_type_table(Ttable* table);
void create_type_table(Ttable table);
void push_type(Ttable table);
void pop_type();

int insert_type(Ttable table,type t)
{
	//table.t[cont]=t;
	table.t[table.cont]=t;
	table.cont++;
	return table.cont-1;
}

type create_type(int type,int dim,int width,int base)
{
	type tmp;
	tmp.type=type;
	tmp.dim=dim;
	tmp.width=width;
	tmp.base=base;
	return tmp;
}

//int insert_type(Ttable* table,type t)



//void create_type_table(Ttable* table)
void create_type_table(Ttable table)
{
	type t_char = create_type(0,-1,1,-1);
	type t_int = create_type(1,-1,4,-1);
	type t_float = create_type(1,-1,8,-1);
	type t_double = create_type(2,-1,16,-1);
	type t_array = create_type(3,-1,1,-1);
	insert_type(table,t_int);
	insert_type(table,t_float);
	insert_type(table,t_double);
	insert_type(table,t_array);
	insert_type(table,t_char);
	/*type t_float = create_type(2,-1,8,-1);
	type t_doble = create_type(3,-1,16,-1);*/
}

void push_type(Ttable table)
{
	Tstack[contTstack] = table;
	contTstack++;
}
void pop_type()
{
	Tstack[contTstack-1].cont=0;
	contTstack--;
}

int getTypeBase(int i)
{
	return Tstack[contTstack-1].t[i].base;
}
int getWidthElement(int i)
{
	return Tstack[contTstack-1].t[i].width;
}

#endif
