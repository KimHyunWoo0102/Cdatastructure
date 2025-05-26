#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
	char op, g;
	int isRun = TRUE, e;

	while (isRun) {
		scanf(" %c", &op);

		switch (op) {
		case 'a':
			scanf("%d %c", &e, &g);
			printf("addShare! e = %d, g = %c\n", e, g);
			break;
		case 'r':
			printf("removeShare!\n");
			break;
		case 'e':
			printf("traverse shared elements!\n");
			break;
		case 'g':
			printf("traverse shared groups!\n");
			break;
		default:
			printf("error : invalid input!\n");
			isRun = FALSE;
			break;
		}
	}
}