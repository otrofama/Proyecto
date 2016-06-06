/**
 *
 *
 *
 *
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct LinkedList List;
typedef struct Tupla Tupla;
typedef struct Nodo Nodo;


#if 1
struct Tupla
{
	char* str;
	int token;
};
#endif

/*
 * struct Tupla
 * {
 * 	char* str;
 * 	int token;
 * 	int typeID;
 * 	int typeVAR;
 * 	float dir;
 * 	List* list;
 * 	int totalParams;
 * }
 */

struct Nodo
{
	Tupla tupla;
	Nodo* next;
};
struct LinkedList
{
	Nodo* root;
	int num;
};
//definiciones de funciones que se emplean para crear la tabla de símbolos.

int insert_end(List* list, char *str, int token);
Nodo* crea_nodo(char* str, int token);
int search(char* str, List* list);
void init_list(List *list);
List* init(List *list);
void print(List* list);
/**
 * void error(char* msg);
 */

#endif
