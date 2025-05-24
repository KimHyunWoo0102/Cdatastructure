#include <stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int WhoIsPrecede(int d1, int d2) {
	return d1 < d2;
}

int PointPrecede(Point* p1, Point* p2) {
	if (p1->xpos < p2->xpos)
		return 0;
	else if (p1->xpos == p2->xpos && p1->ypos < p2->ypos)
		return 0;
	return 1;
}

int main() {
	Point* ppos;
	List list;

	ListInit(&list);
	SetSortRule(&list, PointPrecede);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 3);
	LInsert(&list, ppos);
	
	printf("데이터의 개수 %d\n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	return 0;
}