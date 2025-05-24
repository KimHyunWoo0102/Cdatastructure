#pragma once

#define FALSE 0
#define TRUE 1
#define MAX_SIZE 100

typedef int LData;

//List�� ȣȯ�Ǿ�������.
//main������ List �� ������ ������ �����Ѵ�.
//��������� List�� ��� ���� �����ټ� ����

typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _linkedList {
	Node* tail;
	Node* cur;
	Node* prev;
	int numOfData;
}LinkedList;

typedef LinkedList List;

int isEmpty(List* plist);

void ListInit(List* plist);
void LInsert(List* plist, LData data);
void LInsertFront(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);//���� ������ ������ ����
int LCount(List* plist);