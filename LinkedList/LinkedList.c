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
	//�տ� �־�� �ϸ� Comp�� True �ڿ� �־���ϸ���� FALSE�� �����ؼ�
	//TRUE�� ���ö����� ��

	//head dummy��� ���� �����ϱ�
	//dummy�� �ִٸ� �׳� �ְ�
	//�����Ͱ� �ϳ��� �ִٸ� �� ���ؼ� True�� ��ĭ �ڷ� �а�
	//False�� ���ڸ��� ����
	int compData = 0;
	if (LFirst(plist, &compData)) {

	}
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
}//���� ������ ������ ����
int LCount(List* plist) { return plist->numOfData; }
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2)) { plist->comp = comp; }