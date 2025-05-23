#include "ArrayList.h"
#include<stdio.h>

// main������ �� ���� �������� ���
int main() {
	int data;
	List list;
	ListInit(&list);

	for (int i = 0; i < 10; i++)
		LInsert(&list, i);
	//LInsert(&list, 55);
	
	int sum = 0;
	if (LFirst(&list, &data)) {
		sum += data;

		while (LNext(&list, &data))
			sum += data;
	}

	PrintList(&list);

	printf("sum = %d\n", sum);
	if (LFirst(&list, &data)) {
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	PrintList(&list);

	return 0;
}