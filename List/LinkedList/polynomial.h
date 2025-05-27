#pragma once

typedef struct poly {
	int coef;
	int exp;
}Poly;

void SetPoly(Poly* poly, int coef, int exp);
void ShowPoly(Poly* poly);
int PolyCmp(Poly* p1, Poly* p2);

