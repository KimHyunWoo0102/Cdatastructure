#pragma once
#include"employeeInfo.h"

#define FALSE 0
#define TRUE 1
#define MAX_SIZE 100

typedef EmployeeInfo* LData;

//List�� ȣȯ�Ǿ�������.
//main������ List �� ������ ������ �����Ѵ�.
//��������� List�� ��� ���� �����ټ� ����

typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _clinkedList {
	Node* tail;
	Node* cur;
	Node* prev;
	int numOfData;
}CLL;

typedef CLL List;

int isEmpty(List* plist);

void ListInit(List* plist);
void LInsert(List* plist, LData data);
void LInsertFront(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);//���� ������ ������ ����
int LCount(List* plist);