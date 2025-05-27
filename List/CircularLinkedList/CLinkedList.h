#pragma once
#include"employeeInfo.h"

#define FALSE 0
#define TRUE 1
#define MAX_SIZE 100

typedef EmployeeInfo* LData;

//List가 호환되었으면함.
//main에서는 List 만 가지고 연산을 진행한다.
//헤더내에서 List를 어떤걸 쓸지 정해줄수 있음

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
LData LRemove(List* plist);//직전 참조한 데이터 삭제
int LCount(List* plist);