#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H
#include <stdio.h>
#include <string.h>
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
struct _type
{
	int type;
	int dim;
	int widht;
	int base;
};
struct _type_table
{
	type _type_table[TAM_TTABLE];
	int cont;
};
typedef struct _type type;
Ttable Tstack[TAM_TTABLE];
int insert_type(Ttable* table,type t)
{
	table.t[cont]=t;
	table.cont++;
	return table.cont-1;
}

type create_type(int type,int dim,int widht,int base)
{
	type tmp;
	tmp.type=type;
	tmp.dim=dim;
	tmp.widht=widht;
	tmp.base=base;
	return tmp;
}
void create_type_table(Ttable* table)
{
	type t_char = create_type(0,-1,1,-1);
	type t_int = create_type(1,-1,4,-1);
	type t_float = create_type(1,-1,8,-1);
	type t_double = create_type(2,-1,16,-1);
	type t_array = create_type(3,-1,1,-1);
	insert_type(tabla,t_int);
	insert_type(tabla,t_float);
	insert_type(tabla,t_double);
	insert_type(tabla,t_array);
	insert_type(tabla,t_char);
	/*type t_float = create_type(2,-1,8,-1);
	type t_doble = create_type(3,-1,16,-1);*/
}


#endif
