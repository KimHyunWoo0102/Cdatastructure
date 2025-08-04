#include"SimpleHeap.h"
#include<stdio.h>

int main() {
	Heap heap;
	HeapInit(&heap);

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