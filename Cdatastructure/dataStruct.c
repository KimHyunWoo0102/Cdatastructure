#include<stdio.h>
#include <stdlib.h>

typedef struct _userdata {
	int age;
	char name[32];
	char phone[32];
	struct _userdata* pNext;
}USERDATA;

typedef enum MY_MENU { EXIT, NEW, SEARCH, PRINT, REMOVE }MY_MENU;
MY_MENU PrintMenu() {
	MY_MENU input = 0;

	system("cls");
	printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n:");
	scanf_s("%d%*c", &input);
	return input;
}
int main() {
	MY_MENU menu = 0;
	while (menu = PrintMenu()) {
		switch (menu) {
		case NEW:
			break;
		case SEARCH:
			break;
		case PRINT:
			break;
		case REMOVE:
			break;
		default:
			break;
		}
	}

	puts("bye~");
}