#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct _userdata {
	int age;
	char name[32];
	char phone[32];
	struct _userdata* pNext;
}USERDATA;

USERDATA* pHead;

typedef enum MY_MENU { EXIT, NEW, SEARCH, PRINT, REMOVE }MY_MENU;
MY_MENU PrintMenu() {
	MY_MENU input = 0;

	system("cls");
	printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n:");
	scanf_s("%d%*c", &input);
	return input;
}

void PrintList() {
	if (pHead == NULL || pHead->pNext == NULL)
		return;

	USERDATA* iter = pHead->pNext;

	while (iter != NULL)
	{
		printf("[%p] %d %s %s [%p]\n",
			iter,
			iter->age, iter->name, iter->phone,
			iter->pNext);
		iter = iter->pNext;
	}

	_getch();
}

void appendList() {
	USERDATA* newNode = malloc(sizeof(USERDATA));

	
	printf("추가할 user의 데이터를 입력하세요.\n나이:");
	scanf_s("%d", &(newNode->age));

	printf("이름:");
	scanf_s("%s", newNode->name, sizeof(newNode->name));
	printf("전화번호:");
	scanf_s("%s", newNode->phone, sizeof(newNode->phone));

	USERDATA* iter = pHead;

	while (iter->pNext != NULL) {
		iter = iter->pNext;
	}

	newNode->pNext = iter->pNext;
	iter->pNext = newNode;
}

int deleteNode() {

}
int main() {
	MY_MENU menu = 0;
	pHead = malloc(sizeof(USERDATA));
	pHead->pNext = NULL;

	while (menu = PrintMenu()) {
		switch (menu) {
		case NEW:
			appendList();
			break;
		case SEARCH:
			break;
		case PRINT:
			PrintList();
			break;
		case REMOVE:
			break;
		default:
			break;
		}
	}

	USERDATA* iter = pHead;
	while (iter != NULL) {
		USERDATA* temp = iter;
		iter = iter->pNext;
		free(temp);
	}
	puts("bye~");
}