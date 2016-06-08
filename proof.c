#include <stdio.h>
#include "symboltable.h"
//#include "stack.h"


int main(int argc, char const *argv[])
{
	#if 0
	Stack *stack=NULL;
	initialise(stack);
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
#if 0
void initialise(Stack *s)
{
// this function is to initialise the stack
    s->size = 0;  // set the size of the stack to 0
    s->top = NULL; // top of the stack now points to NULL
}

void push(Stack *s, int value)
{
// Push function to add data to the top of the stack
    Node *np;  // make a node pointer

    np = (Node *)malloc(sizeof(Node));  // we now have some space for a node
    if (np == NULL)
	{
        // The program will crash if the memory was not allocated
        exit(1);
    }

    np->item = value; // put the value we want to allocate in the node
    np->next = s->top; // copy the last address that was at the top of the stack
    s->top = np; // now the top is pointing to the new top of the stack

    // increment the size of the stack count
    s->size++;
}

int pop(Stack *s)
{
	// Pop function to remove data to the top of the stack
    int temp;
    Node *np;
    if (s->top == NULL)
	{
        // The program will crash if the stack is empty
        exit(1);
    }
	// node pointer is now pointing to the top of the stack
    np = s->top;
	// store the valuse currently at the top of the stack
    temp = s->top->item;
	// make the top of the stack point to the node below
    s->top = np->next;
	// decrement the size of the stack count
    s->size--;
	// free the memory at the address the np is pointing to
    free(np);
	return temp; // return the value that was popped off the stack
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
#endif
