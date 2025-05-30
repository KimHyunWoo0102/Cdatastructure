#pragma once

#define FALSE 0 
#define TRUE 1
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack,Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);