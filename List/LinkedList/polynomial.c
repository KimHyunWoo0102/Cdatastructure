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

int PolyCmp(Poly* p1, Poly* p2) {
    if (p1->exp > p2->exp)
        return 0;   // p1이 앞에 있어야 하므로 여기서 삽입
    else
        return 1;   // 계속 순회
}

