#pragma once

#define TRUE		1
#define FALSE		0

#define HEAP_LEN	100

typedef char HData;
typedef int Priority;

typedef int (*PriorityComp)(HData d1, HData d2);

typedef struct _heap {
	PriorityComp comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* heap, PriorityComp pc);
int HIsEmpty(Heap* heap);

void HInsert(Heap* heap, HData data, Priority pr);
HData HDelete(Heap* heap);