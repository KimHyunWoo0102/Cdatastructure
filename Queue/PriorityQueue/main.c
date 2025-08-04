#include"UsefulHeap.h"
#include<stdio.h>

int DataPrioritycomp(char c1, char c2) {
	return c2 - c1;
}

int main() {
	Heap heap;
	HeapInit(&heap, DataPrioritycomp);

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'b', 2);
	HInsert(&heap, 'c', 3);
	printf("%c \n", HDelete(&heap));
	

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'b', 2);
	HInsert(&heap, 'c', 3);
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));
	return 0;
}