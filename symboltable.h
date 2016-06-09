#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_ID 50
#define TAM_SYM_TABLE 100
#define TAM_PILA 10

int i;
//int contSstack=0;
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
int insert_symbol(int table,symbol s);
int get_Symbol(char* id,int table);
params getParams(char* id,int table);
void setParams(char* id,params p,int table);
int getTypeSymbol(char* id,int table);
int getTypeVar(char* id,int table);
void push_symbol();
void pop_symbol();
void printStack();

int j=0;
symbol create_symbol(char* id,int type,int typeVar,int dir, params param)
{
	symbol tmp;
	strcpy(tmp.id,id);
	tmp.type=type;
	tmp.typeVar=typeVar;
	tmp.dir=dir;
	tmp.param=param;
	printf("Simbolo %d,id:%s,ty:%d,tyv:%d,dir:%d\n",j,tmp.id,tmp.type,tmp.typeVar,tmp.dir );
	j++;
	return tmp;
}

int insert_symbol(int table,symbol s)
{
	int i=0;

	printf("Simbolo %d,id:%s,ty:%d,tyv:%d,dir:%d\n",13,s.id,s.type,s.typeVar,s.dir );

	i=get_Symbol(Sstack[table].s[Sstack[table].cont].id,contSstack);
	printf("%dasd\n",i );
	//if (i == -1 )
	if (i != -1 )
	{
		printf("asdasdadasdasd\n");
		Sstack[table].s[Sstack[table].cont] = s;
		Sstack[table].cont++;
		printf("s%d\n", Sstack[table].cont-1);
		return Sstack[table].cont-1;
	}
	return -1;
}

int get_Symbol(char* id,int table)
{
	printf("getsymbolss\n" );
	printf("%s:pila\n", Sstack[table].s[i].id);
	for (i = 0; i < Sstack[table].cont; i++)
	{
		if (strcmp(Sstack[table].s[i].id,id) == 0)
			return i;
	}
	return -1;
}

void printStack()
{
	int i,j;
	for ( i = 0; i < contSstack; i++)
	{
		for (j = 0; j < Sstack[i].cont; j++)
		{
			printf("KJHGFDS%s\n",Sstack[i].s[j].id );
			printf("KJHGFDS%d\n", Sstack[i].s[j].type);
			printf("KJHGFDS%d\n", Sstack[i].s[j].typeVar);
			printf("KJHGFDS%d\n", Sstack[i].s[j].dir);
		}
	}
}

void push_param(int i, params* param)
{
	param->type[param->cont] =i;
	param->cont++;
}

params getParams(char* id,int table)
{
	int i = get_Symbol(id,table);
	return Sstack[table].s[i].param;
}

void setParams(char* id,params p,int table)
{
	int i=get_Symbol(id,table);
	Sstack[table].s[i].param=p;
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
