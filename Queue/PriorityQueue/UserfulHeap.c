#include"UsefulHeap.h"

void HeapInit(Heap* heap, PriorityComp pc){
	heap->comp = pc;
	heap->numOfData = 0;
}

int HIsEmpty(Heap* heap)
{
	return (heap->numOfData == 0) ? TRUE : FALSE;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

int GetHiPriChildIDX(Heap* heap, int idx) {
	if (GetLChildIDX(idx) > heap->numOfData)
		return 0;
	else if (GetLChildIDX(idx) == heap->numOfData)
		return GetLChildIDX(idx);
	else {
		if (heap->comp(heap->heapArr[GetLChildIDX(idx)], 
			heap->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* heap, HData data, Priority pr)
{
	int idx = heap->numOfData + 1;
	
	while (idx != 1) {
		if (heap->comp(data,heap->heapArr[GetParentIDX(idx)]>0)) {
			heap->heapArr[idx] = heap->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else break;
	}

	heap->heapArr[idx] = data;
	heap->numOfData++;
}

HData HDelete(Heap* heap)
{
	HData retData = heap->heapArr[1]; //삭제할 데이터 저장
	HData lastElem = heap->heapArr[heap->numOfData]; //마지막 노드 가져오기

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(heap, parentIdx)) {
		if (heap->comp(lastElem,heap->heapArr[childIdx]>=0))
			break;

		heap->heapArr[parentIdx] = heap->heapArr[childIdx];
		parentIdx = childIdx;
	}

	heap->heapArr[parentIdx] = lastElem;
	heap->numOfData--;
	return retData;
}
