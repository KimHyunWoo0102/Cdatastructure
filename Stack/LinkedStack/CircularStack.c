#include "CircularStack.h"

void StackInit(Stack* pstack) {
	ListInit(&(pstack->list));
}
int SIsEmpty(Stack* pstack) {
	return isEmpty(&pstack->list);
}

void SPush(Stack* pstack, Data data) {
	LInsertFront(&(pstack->list), data);
}
Data SPop(Stack* pstack) {
	Data data;
	LFirst(&(pstack->list), &data);
	LRemove(&(pstack->list));
	return data;
}
Data SPeek(Stack* pstack) {
	Data data;
	LFirst(&(pstack->list), &data);
	return data;
}