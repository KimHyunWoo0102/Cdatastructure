#include "DoublyLinkedList.h"
#include <stdio.h>
#include<stdlib.h>

int isEmpty(List* plist) {
	return plist->head == NULL;
}

void ListInit(List* plist) {
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}
void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (!isEmpty(plist))
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;
	
	plist->numOfData++;
}

int LFirst(List* plist, Data* pdata) {
	if (isEmpty(plist))
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List* plist, Data* pdata) {
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

int LCount(List* plist) { return plist->numOfData; }