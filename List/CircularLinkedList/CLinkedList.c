#include "CLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
int isEmpty(List* plist) {
	return plist->tail == NULL;
}

void ListInit(List* plist) {
	plist->numOfData = 0;
	plist->tail = NULL;
	plist->cur = NULL;
	plist->prev = NULL;
}

void LInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (isEmpty(plist)) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	plist->numOfData++;
}

void LInsertFront(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (isEmpty(plist)) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	plist->numOfData++;
}

int LFirst(List* plist, LData* pdata) {
	if (isEmpty(plist))
		return FALSE;

	plist->cur = plist->tail->next;
	plist->prev = plist->tail;
	
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (isEmpty(plist))
		return FALSE;//어차피 순환이니 빈거 아니면 노상관

	plist->prev = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}
LData LRemove(List* plist) {
	if (isEmpty(plist))
		return FALSE;

	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->prev;
	}

	plist->prev->next = plist->cur->next;
	plist->cur->next = NULL;
	plist->cur = plist->prev;

	free(rpos);
	plist->numOfData--;
	return rdata;
}

int LCount(List* plist) { return plist->numOfData; }