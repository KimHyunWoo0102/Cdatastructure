#include "ArrayList.h"
#include<stdio.h>

// main������ �� ���� �������� ���
int main() {
	int data;
	List list;
	ListInit(&list);

	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 44);
	//LInsert(&list, 55);
	

	if (LFirst(&list, &data)) {
		printf("%d\n", data);

		while (LNext(&list, &data))
			printf("%d\n", data);
	}

	/*if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}*/

	return 0;
}