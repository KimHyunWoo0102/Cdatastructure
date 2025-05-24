#include <stdio.h>
#include"LinkedList.h"

int main() {
	List list;
	int data;

	ListInit(&list);
	LInsert(&list, 10);
	LInsert(&list, 15);
	LInsert(&list, 20);

	printf("%d\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d\n", data);

		while (LNext(&list, &data)) {
			printf("%d\n", data);
		}
	}

	if (LFirst(&list, &data))
		LRemove(&list);

	printf("%d\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d\n", data);

		while (LNext(&list, &data)) {
			printf("%d\n", data);
		}
	}
	return 0;
}