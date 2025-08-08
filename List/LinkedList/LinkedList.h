#pragma once
#include"../../Slot2.h"
#define FALSE 0
#define TRUE 1
#define MAX_SIZE 100

//typedef int LData;
typedef Slot LData;

//List�� ȣȯ�Ǿ�������.
//main������ List �� ������ ������ �����Ѵ�.
//��������� List�� ��� ���� �����ټ� ����

typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _linkedList {
	Node* head;
	Node* cur;
	Node* prev;
	int numOfData;
	int (*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;

int isEmpty(List* plist);

void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);//���� ������ ������ ����
int LCount(List* plist);
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));