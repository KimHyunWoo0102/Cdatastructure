#include<stdio.h>
#include<stdlib.h>
#include"CLinkedList.h"
#include "employeeInfo.h"

//int main() {
//	List list;
//	int data, nodeNum;
//	ListInit(&list);
//
//	LInsert(&list, 3);
//	LInsert(&list, 4);
//	LInsert(&list, 5);
//	LInsertFront(&list, 2);
//	LInsertFront(&list, 1);
//
//	if (LFirst(&list, &data)) {
//		printf("%d ", data);
//
//		for (int i = 0; i < LCount(&list) * 3 - 1; i++) {
//			if (LNext(&list, &data))
//				printf("%d ", data);
//		}
//	}
//
//	putchar('\n');
//
//	nodeNum = LCount(&list);
//
//	if (nodeNum != 0) {
//		LFirst(&list, &data);
//		if (data % 2 == 0)
//			LRemove(&list);
//
//		for (int i = 0; i < nodeNum - 1; i++)
//		{
//			LNext(&list, &data);
//			if (data % 2 == 0)
//				LRemove(&list);
//		}
//	}
//
//	if (LFirst(&list, &data)) {
//		printf("%d ", data);
//
//		for (int i = 0; i < LCount(&list) - 1; i++)
//		{
//			if(LNext(&list,&data))
//				printf("%d ", data);
//		}
//	}
//	return 0;
//}
EmployeeInfo* GetDutyInfoAfterNDays(List* plist, const char* name, int day) {
	EmployeeInfo* ppos;
	if (LFirst(plist, &ppos)) {
		if (!strcmp(ppos->name, name));
		else {
			while (LNext(plist, &ppos)) {
				if (!strcmp(ppos->name, name))
					break;
			}
		}
	}

	for (int i = 0; i < day; i++)
		LNext(plist, &ppos);

	return ppos;
}

int main() {
	List list;
	EmployeeInfo* ppos;

	ListInit(&list);
	ppos = MakeEmployeeInfo(1, "kim");
	LInsert(&list, ppos);

	ppos = MakeEmployeeInfo(2, "choi");
	LInsert(&list, ppos);

	ppos = MakeEmployeeInfo(3, "lee");
	LInsert(&list, ppos);

	ppos = MakeEmployeeInfo(4, "hong");
	LInsert(&list, ppos);

	ppos = GetDutyInfoAfterNDays(&list, "kim", 7);
	ShowEmployeeInfo(ppos);
	printf("저장된 데이터 수 : %d\n", LCount(&list));

	int len = LCount(&list);
	if (LFirst(&list, &ppos)) {
		LRemove(&list);

		for (int i = 0; i < len - 1; i++)
		{
			if (LNext(&list, &ppos))
				LRemove(&list);
		}
	}

	printf("저장된 데이터 수 : %d\n", LCount(&list));
	
}