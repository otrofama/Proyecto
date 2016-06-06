/**
 *
 *
 *
 *
 */

#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct TypeTable Types;
typedef struct Tupla Tupla;
typedef struct Nodo Nodo;


#if 0
struct Tupla
{
	char* str;
	int token;
};
#endif
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
