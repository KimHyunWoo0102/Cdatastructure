#include "ArrayList.h"
#include<stdio.h>

int isEmpty(List* plist)
{
	return plist->numOfData == 0;
}

int isFull(List* plist)
{
	return plist->numOfData == MAX_SIZE;
}

void ListInit(List* plist)
{
	plist->curPosition = -1;//증가시키고 참조해야 LRemove등에서 사용가능
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data)
{
	 //TODO : 첫번재 위치부터 삽입
	if (isFull(plist)) {
		printf("Error : full list exception\n");
		return;
	}

	for (int i = plist->numOfData-1; i >= 0; i--)
		plist->arr[i + 1] = plist->arr[i];

	plist->arr[0] = data;
	plist->numOfData++;
}

int LFirst(List* plist, LData* pdata)
{
	plist->curPosition = -1;
	if (isEmpty(plist))
	{
		printf("Error : empty list\n");
		return FALSE;
	}

	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->numOfData - 1 == plist->curPosition) {
		return FALSE;
	}

	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	if (isEmpty(plist)) {
		printf("Remove : empty list exception. can't remove data.\n");
	}

	LData remove = plist->arr[plist->curPosition];

	for (int i = plist->curPosition; i < plist->numOfData - 1; i++)
		plist->arr[i] = plist->arr[i + 1];
	
	plist->numOfData--;
	plist->curPosition--;
	return remove;
}

void PrintList(List* plist) {
	LData data;

	if (LFirst(plist, &data)) {
		printf("[%d,", data);

		while (LNext(plist, &data)) {
			printf(" %d,", data);
		}

		printf("]\n");
	}
}

int LCount(List* plist)
{
	return plist->numOfData;
}
