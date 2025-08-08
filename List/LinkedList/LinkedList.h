#pragma once
#include"../../Slot2.h"
#define FALSE 0
#define TRUE 1
#define MAX_SIZE 100

//typedef int LData;
typedef Slot LData;

//List가 호환되었으면함.
//main에서는 List 만 가지고 연산을 진행한다.
//헤더내에서 List를 어떤걸 쓸지 정해줄수 있음

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
LData LRemove(List* plist);//직전 참조한 데이터 삭제
int LCount(List* plist);
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));