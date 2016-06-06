#include <stdio.h>
#include "symboltable.h"


int main(int argc, char const *argv[])
{
	#if 0
	Symbols* symbols = NULL;
	symbols = init(symbols);
	init_symbols(symbols);
	insert_end(symbols,"first",1);
	insert_end(symbols,"2nd",2);
	insert_end(symbols,"3rd",3);
	insert_end(symbols,"4th",4);
	printf("%d\n", search("2",symbols));
	printf("%d\n", search("2nd",symbols));
	printf("%d\n", search("12",symbols));
	printf("%d\n", search("first",symbols));
	printf("%d\n", search("4th",symbols));
	#endif
	return 0;
}

Symbols* init(Symbols *symbols)
{
	symbols=(Symbols*)malloc(sizeof(Symbols));
	return symbols;
}

int insert_end(Symbols* symbols, char *str, int token)
{
	int pos = search(str,symbols);
	if (pos != -1)
	{
		return pos;
	}

	Nodo* newtmp = crea_nodo(str, token);
	Nodo* tmp = symbols->root;

	if (!symbols->root)
	{
		symbols->root = newtmp;
	}
	else
	{
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newtmp;
	}
	symbols->num++;
	return symbols->num -1;
}

Nodo* crea_nodo(char* str, int token)
{
	Nodo* newnodo = (Nodo *)malloc(sizeof(Nodo));
	int len = strlen(str);
	newnodo->tupla.str = malloc(len*sizeof(char));
	strcpy(newnodo->tupla.str,str);
	newnodo->tupla.token=token;
	newnodo->next = NULL;
	return newnodo;
}
int search(char* str, Symbols* symbols)
{
	Nodo* tmp = symbols->root;
	int pos = 0;

	while(tmp)
	{
		if (strcmp(tmp->tupla.str,str) == 0)
		{
			return pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return -1;
}

void init_symbols(Symbols *symbols)
{
	symbols->root = NULL;
	symbols->num = 0;
}
void print(Symbols* symbols)
{
	Nodo* tmp =  symbols->root;
	if (tmp == NULL)
		exit(-1);
	printf("Tabla de indices:\n");
	while(tmp != NULL)
	{
		printf("<%s, \t%d>\n",tmp->tupla.str, tmp->tupla.token);
		tmp = tmp->next;
	}
}
