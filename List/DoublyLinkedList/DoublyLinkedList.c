#include "DoublyLinkedList.h"
#include <stdio.h>
#include<stdlib.h>

int isEmpty(List* plist) {
	return plist->head->next == plist->tail;
}

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	
	plist->head->next = plist->tail;
	plist->tail->prev = plist->head;

	plist->tail->next = NULL;
	plist->head->next = NULL;

	plist->cur = plist->head;
	plist->numOfData = 0;
}
void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	plist->tail->prev->next = newNode;
	newNode->prev = plist->tail->prev;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;
	
	plist->numOfData++;
}

int LFirst(List* plist, Data* pdata) {
	if (isEmpty(plist))
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List* plist, Data* pdata) {
	if (plist->cur->prev == plist->head)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List* plist) {
	Node* rpos = plist->cur, * prev = plist->cur->prev;
	Data Ldata = rpos->data;

	prev->next = plist->cur->next;
	plist->cur->next->prev = prev;
	plist->cur = prev;
	free(rpos);

	plist->numOfData--;
	return Ldata;
}

int LCount(List* plist) { return plist->numOfData; }