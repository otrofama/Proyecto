/*
 *	C Stack implementation
 * 	https://gist.github.com/RenatoUtsch/4162787
 */
#if 0
#include <stdlib.h>
#include <string.h>
#include "stack.h"

typedef struct StackNode {
	StackItem item;				/** The data of this node. **/
	struct StackNode *next;		/** The next node (the one below the top). **/
} StackNode;

struct Stack {
	size_t count; 	/** The number of items in the stack. **/
	StackNode *top;	/** The top item of the stack. **/
};

Stack *stackCreate()
{
	/* Create a stack and set everything to the default values. */
	Stack *stack = (Stack *) malloc(sizeof *stack);
	if(stack == NULL)
		return NULL;

	stack->count = 0;
	stack->top = NULL;

	return stack;
}

void stackDestroy(Stack *stack)
{
	stackClean(stack);
	free(stack);
}

void stackClean(Stack *stack)
{
	while(!stackIsEmpty(stack))
		stackPop(stack);
}

bool stackIsEmpty(Stack *stack)
{
	return stack->top == NULL ? true : false;
}

size_t stackSize(Stack *stack)
{
	return stack->count;
}

StackItem stackTop(Stack *stack)
{
	return stack->top->item;
}

bool stackPush(Stack *stack, StackItem item)
{
	StackNode *newNode = (StackNode *) malloc(sizeof *newNode);
	if(newNode == NULL)
		return false;

	newNode->item = item;
	newNode->next = stack->top;
	stack->top = newNode;

	stack->count += 1;
	return true;
}

StackItem stackPop(Stack *stack)
{
	StackNode *oldTop;
	StackItem item;

	if(stack->top == NULL)
		return 0; /** @todo Make a better way to return this error. **/

	oldTop = stack->top;
	item = oldTop->item;
	stack->top = oldTop->next;
	free(oldTop);
	oldTop = NULL;

	stack->count -= 1;
	return item;
}
#endif

/*
 * Author: Sam Jones
 * Description: Stack revision
 * Created: 18/04/2013
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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

/*
 * int main()
 * {
 *     int pv; // make a pop value variable
 *     Stack stk; // this is a stack object
 *
 *     initialise(&stk); // initialise the data structure to 0
 *
 *     push(&stk, 7); // push the value 7 on to the stack
 *     push(&stk, 9); // push the value 9 on to the stack
 * 	// The stack now contains 9, 7 and NULL
 *
 *     pv = pop(&stk);
 *     // the value 9 has been popped off the stack so now only 7 and NULL remains
 *     pv = pop(&stk);
 *     // the value 7 has been popped off the stack so now only NULL remains
 *
 *     return 0;
 * }
 */
