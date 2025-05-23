#include "ArrayList.h"
#include"Point.h"
#include<stdio.h>
#include<stdlib.h>

//void TestIntArrayList() {
//	LData data;
//	List list;
//	ListInit(&list);
//
//	for (int i = 0; i < 10; i++)
//		LInsert(&list, i);
//	//LInsert(&list, 55);
//	
//	int sum = 0;
//	if (LFirst(&list, &data)) {
//		sum += data;
//
//		while (LNext(&list, &data))
//			sum += data;
//	}
//
//	PrintList(&list);
//
//	printf("sum = %d\n", sum);
//	if (LFirst(&list, &data)) {
//		if (data % 2 == 0 || data % 3 == 0)
//			LRemove(&list);
//
//		while (LNext(&list, &data)) {
//			if (data % 2 == 0 || data % 3 == 0)
//				LRemove(&list);
//		}
//	}
//
//	PrintList(&list);
//
// 
//}
// main에서는 이 역할 고정으로 사용
int main() {
	Point* ppos, compPos;
	List list;
	
	ListInit(&list);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}

	if (LFirst(&list, &ppos)) {
		ppos = LRemove(&list);
		free(ppos);

		while (LNext(&list, &ppos))
		{
			ppos = LRemove(&list);
			free(ppos);
		}
	}

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}

	return 0;
}