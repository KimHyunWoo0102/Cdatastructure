#include"ExpressionTree.h"
#include<stdio.h>

int main() {
	const char* exp = "12+7*";
	BTreeNode* result = MakeExpTree(exp);
	
	printf("전위 표기법의 수식 : ");
	ShowPrefixTypeExp(result); printf("\n");

	printf("중위 표기법의 수식 : ");
	ShowInfixTypeExp(result); printf("\n");

	printf("후위 표기법의 수식 : ");
	ShowPostfixTypeExp(result); printf("\n");

	printf("%d ", EvaluateExpTree(result));
	return 0;
}