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

USERDATA* g_pHeadNode;

typedef enum MY_MENU { EXIT, NEW, SEARCH, PRINT, REMOVE }MY_MENU;

MY_MENU PrintMenu() {
	MY_MENU input = 0;

	system("cls");
	printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n:");
	scanf_s("%d%*c", &input);
	return input;
}

void PrintList() {
	if (g_pHeadNode == NULL)
		return;

	USERDATA* iter = g_pHeadNode;

	while (iter != NULL)
	{
		printf("[%p] %d %s %s [%p]\n",
			iter,
			iter->age, iter->name, iter->phone,
			iter->pNext);
		iter = iter->pNext;
	}
}

USERDATA* SearchByName(const char* name) {
	USERDATA* iter = g_pHeadNode;

	while (iter != NULL)
	{
		if (!strcmp(iter->name, name)) {
			printf("\"%s\": Found\n", name);
			return iter;
		}
		iter = iter->pNext;
	}
	printf("\"%s\": Not Found\n", name);
	return NULL;
}

void AppendList(int age, const char* name, const char* phone) {
	USERDATA* newNode = (USERDATA*)malloc(sizeof(USERDATA));

	
	newNode->age = age;
	strcpy_s(newNode->name, sizeof(newNode->name), name);
	strcpy_s(newNode->phone, sizeof(newNode->phone), phone);
	newNode->pNext = NULL;

	if (g_pHeadNode == NULL)
		g_pHeadNode = newNode;
	else {
		USERDATA* iter = g_pHeadNode;
		while (iter->pNext != NULL) {
			iter = iter->pNext;
		}

		iter->pNext = newNode;
	}
}
void InitDummyData() {
	AppendList(20, "kimhyunwoo", "01052557689");
	AppendList(20, "kimsiwoo", "01052557689");
	AppendList(20, "kimjiwoo", "01052557689");
	AppendList(20, "kimminjeong", "01056232262");
}

int deleteByName(const char*name) {
	USERDATA* current = g_pHeadNode, *prev = g_pHeadNode;

	if (!strcmp(g_pHeadNode->name, name)) {
		g_pHeadNode = g_pHeadNode->pNext;
		free(current);
		return 1;
	}

	current = current->pNext;

	while (current->pNext != NULL) {
		if (!strcmp(current->name, name)) {
			prev->pNext = current->pNext;
			free(current);
			return 1;
		}
		prev = current;
		current = current->pNext;
	}

	return -1;
}

void ReleaseList(){
	USERDATA* iter = g_pHeadNode;
	while (iter != NULL) {
		USERDATA* temp = iter;
		iter = iter->pNext;
		printf("Delete: [%p] %d %s %s [%p]\n",
			temp,
			temp->age, temp->name, temp->phone,
			temp->pNext);
		free(temp);
	}
}

void run() {
	MY_MENU menu = 0;

	while (menu = PrintMenu()) {
		switch (menu) {
		case NEW:
			//AppendList();
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
}

int main() {
	InitDummyData();
	PrintList();
	deleteByName("kimsiwoo");
	PrintList();
	ReleaseList();
	puts("bye~");
}