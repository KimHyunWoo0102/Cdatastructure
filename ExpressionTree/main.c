#include"ExpressionTree.h"
#include<stdio.h>

int main() {
	const char* exp = "12+7*";
	BTreeNode* result = MakeExpTree(exp);
	
	printf("���� ǥ����� ���� : ");
	ShowPrefixTypeExp(result); printf("\n");

	printf("���� ǥ����� ���� : ");
	ShowInfixTypeExp(result); printf("\n");

	printf("���� ǥ����� ���� : ");
	ShowPostfixTypeExp(result); printf("\n");

	printf("%d ", EvaluateExpTree(result));
	return 0;
}