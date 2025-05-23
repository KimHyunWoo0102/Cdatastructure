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
	plist->curPosition = -1;//������Ű�� �����ؾ� LRemove��� ��밡��
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data)
{
	 //TODO : ù���� ��ġ���� ����
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
		printf("Error: No more data to access.\n");
		return FALSE;
	}

	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}
