#include "ArrayStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	return pstack->topIndex == -1;
}

void SPush(Stack* pstack,Data data)
{
	if (pstack->topIndex + 1 <= STACK_LEN)
		return;

	pstack->topIndex++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	Data ret = SPeek(pstack);
	pstack->topIndex--;
	return ret;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIndex];
}
