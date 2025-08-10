#pragma once
#define TRUE 1
#define FALSE 0


typedef struct _bTreeNode BTreeNode;
typedef BTreeNode* Data;

typedef struct _nodeStack {
	Data data;
	struct _nodeStack* next;
}StackNode;

typedef struct _listStack {
	StackNode* head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);