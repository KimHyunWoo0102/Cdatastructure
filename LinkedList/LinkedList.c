#include"LinkedList.h"
#include<stdio.h>
#include<stdlib.h>

int isEmpty(List* plist) {
	return plist->head->next == NULL;
}

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;
	
	plist->numOfData++;
}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	Node* pred = plist->head;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;

	plist->numOfData++;
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List* plist, LData* pdata) {
	if (isEmpty(plist))
		return FALSE;

	plist->cur = plist->head->next;
	plist->prev = plist->head;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->prev = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}
LData LRemove(List* plist) {
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->prev->next = plist->cur->next;
	plist->cur = plist->prev;
	free(rpos);
	plist->numOfData--;

	return rdata;
}//직전 참조한 데이터 삭제
int LCount(List* plist) { return plist->numOfData; }
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) { plist->comp = comp; }