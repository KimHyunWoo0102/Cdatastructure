#include<stdio.h>
#include"InfixToPostfix.h"
#include"StackCalculator.h"

int main() {
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";


	printf("%s = %d\n", exp1, calculate(exp1));
	printf("%s = %d\n", exp2, calculate(exp2));
	printf("%s = %d\n", exp3, calculate(exp3));
	
	return 0;
}