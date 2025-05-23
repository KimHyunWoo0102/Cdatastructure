#pragma once

#define FALSE 0
#define TRUE 1
#define MAX_SIZE 100

typedef int LData;

//List가 호환되었으면함.
//main에서는 List 만 가지고 연산을 진행한다.
//헤더내에서 List를 어떤걸 쓸지 정해줄수 있음

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
LData LRemove(List* plist);//직전 참조한 데이터 삭제
void PrintList(List* plist);
int LCount(List* plist);