#pragma once

#define FALSE 0
#define TRUE 1
#define MAX_SIZE 100

typedef int LData;

//List�� ȣȯ�Ǿ�������.
//main������ List �� ������ ������ �����Ѵ�.
//��������� List�� ��� ���� �����ټ� ����

typedef struct _arrayList {
	LData arr[MAX_SIZE];
	int curPosition;
	int numOfData;
}ArrayList;

typedef ArrayList List;

int isEmpty(List* plist);
int isFull(List* plist);

void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);//���� ������ ������ ����
void PrintList(List* plist);
int LCount(List* plist);