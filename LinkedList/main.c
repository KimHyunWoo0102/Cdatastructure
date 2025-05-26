#include <stdio.h>
#include<stdlib.h>
#include"LinkedList.h"
#include"polynomial.h"

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
	Poly* ppos;
	List a, b;

	ListInit(&a);
	SetSortRule(&a, PointPrecede);

	ppos = (Point*)malloc(sizeof(Point));
	SetPoly(ppos, 3, 4);
	LInsert(&a, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPoly(ppos,8,1);
	LInsert(&a, ppos);

	printf("데이터의 개수 %d\n", LCount(&a));

	if (LFirst(&a, &ppos)) {
		ShowPoly(ppos);

		while (LNext(&a, &ppos))
			ShowPoly(ppos);
	}
	putchar('\n');
	ListInit(&b);
	SetSortRule(&b, PointPrecede);

	ppos = (Point*)malloc(sizeof(Point));
	SetPoly(ppos, 11, 3);
	LInsert(&b, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPoly(ppos, -8, 1);
	LInsert(&b, ppos);


	ppos = (Point*)malloc(sizeof(Point));
	SetPoly(ppos, 4, 0);
	LInsert(&b, ppos);

	printf("데이터의 개수 %d\n", LCount(&b));

	if (LFirst(&b, &ppos)) {
		ShowPoly(ppos);

		while (LNext(&b, &ppos))
			ShowPoly(ppos);
	}

	return 0;
}