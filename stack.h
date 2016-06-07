/**
 * C Stack implementation
 * https://gist.github.com/RenatoUtsch/4162787
 */
#if 0
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>

#if !defined(__bool_true_false_are_defined) && !defined(__cplusplus)
typedef int bool;
#define true 1
#define false 0
#define __bool_true_false_are_defined
#endif

#define StackItem char

typedef struct Stack Stack;

Stack *stackCreate();
void stackDestroy(Stack *stack);
void stackClean(Stack *stack);
bool stackIsEmpty(Stack *stack);
size_t stackSize(Stack *stack);
StackItem stackTop(Stack *stack);
bool stackPush(Stack *stack, StackItem item);
StackItem stackPop(Stack *stack);

#endif
#endif

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int item;
    struct node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Stack;

void initialise(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);

#endif
