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

void AddPoly(List* ret,List* a, List* b) {
	Node* aIter, *bIter;
	Poly* ppos;

	aIter = a->head->next;
	bIter = b->head->next;

	while ((aIter!=NULL) && (bIter!=NULL)) {
		if (aIter->data->exp > bIter->data->exp)
		{
			ppos = (Poly*)malloc(sizeof(Poly));
			SetPoly(ppos, aIter->data->coef, aIter->data->exp);
			LInsert(ret, ppos);
			aIter = aIter->next;
		}
		else if (aIter->data->exp == bIter->data->exp) {
			ppos = (Poly*)malloc(sizeof(Poly));
			SetPoly(ppos, aIter->data->coef + bIter->data->coef, aIter->data->exp);
			LInsert(ret, ppos);
			aIter = aIter->next;
			bIter = bIter->next;
		}
		else {
			ppos = (Poly*)malloc(sizeof(Poly));
			SetPoly(ppos, bIter->data->coef, bIter->data->exp);
			LInsert(ret, ppos);
			bIter = bIter->next;
		}
	}

	while (aIter != NULL) {
		ppos = (Poly*)malloc(sizeof(Poly));
		SetPoly(ppos, aIter->data->coef, aIter->data->exp);
		LInsert(ret, ppos);
		aIter = aIter->next;
	}

	while (bIter != NULL) {
		ppos = (Poly*)malloc(sizeof(Poly));
		SetPoly(ppos, bIter->data->coef, bIter->data->exp);
		LInsert(ret, ppos);
		bIter = bIter->next;
	}

}
void SubPoly(List* ret, List* a, List* b) {
	Node* aIter, * bIter;
	Poly* ppos;

	aIter = a->head->next;
	bIter = b->head->next;

	while ((aIter != NULL) && (bIter != NULL)) {
		if (aIter->data->exp > bIter->data->exp)
		{
			ppos = (Poly*)malloc(sizeof(Poly));
			SetPoly(ppos, aIter->data->coef, aIter->data->exp);
			LInsert(ret, ppos);
			aIter = aIter->next;
		}
		else if (aIter->data->exp == bIter->data->exp) {
			ppos = (Poly*)malloc(sizeof(Poly));
			SetPoly(ppos, aIter->data->coef - bIter->data->coef, aIter->data->exp);
			LInsert(ret, ppos);
			aIter = aIter->next;
			bIter = bIter->next;
		}
		else {
			ppos = (Poly*)malloc(sizeof(Poly));
			SetPoly(ppos, -bIter->data->coef, bIter->data->exp);
			LInsert(ret, ppos);
			bIter = bIter->next;
		}
	}

	while (aIter != NULL) {
		ppos = (Poly*)malloc(sizeof(Poly));
		SetPoly(ppos, aIter->data->coef, aIter->data->exp);
		LInsert(ret, ppos);
		aIter = aIter->next;
	}

	while (bIter != NULL) {
		ppos = (Poly*)malloc(sizeof(Poly));
		SetPoly(ppos, -bIter->data->coef, bIter->data->exp);
		LInsert(ret, ppos);
		bIter = bIter->next;
	}

}
int main() {
	Poly* ppos;
	List a, b, c;

	ListInit(&a);
	SetSortRule(&a, PolyCmp);
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
	SetSortRule(&b, PolyCmp);

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
	putchar('\n');
	ListInit(&c);
	SetSortRule(&c, PolyCmp);
	AddPoly(&c, &a, &b);
	if (LFirst(&c, &ppos)) {
		ShowPoly(ppos);

		while (LNext(&c, &ppos))
			ShowPoly(ppos);
	}
	if (LFirst(&c, &ppos)) {
		LRemove(&c);

		while (LNext(&c, &ppos))
			LRemove(&c);
	}
	putchar('\n');
	ListInit(&c);
	SetSortRule(&c, PolyCmp);
	SubPoly(&c, &a, &b);
	if (LFirst(&c, &ppos)) {
		ShowPoly(ppos);

		while (LNext(&c, &ppos))
			ShowPoly(ppos);
	}
	if (LFirst(&c, &ppos)) {
		LRemove(&c);

		while (LNext(&c, &ppos))
			LRemove(&c);
	}
	if (LFirst(&a, &ppos)) {
		LRemove(&a);

		while (LNext(&a, &ppos))
			LRemove(&a);
	}

	if (LFirst(&b, &ppos)) {
		LRemove(&b);

		while (LNext(&b, &ppos))
			LRemove(&b);
	}
	if (LFirst(&c, &ppos)) {
		LRemove(&c);

		while (LNext(&c, &ppos))
			LRemove(&c);
	}
	return 0;
}