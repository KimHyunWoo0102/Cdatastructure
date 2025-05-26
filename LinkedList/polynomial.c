#include "polynomial.h"

void SetPoly(Poly* poly, int coef, int exp)
{
	poly->coef = coef;
	poly->exp = exp;
}

void ShowPoly(Poly* poly)
{
	printf("%d^%d ", poly->coef, poly->exp);
}

int PolyCmp(Poly* p1, Poly* p2)
{
	if (p1->exp < p2->exp)
		return 0;
	else
		return -1;
}
