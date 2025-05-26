#include<stdio.h>
#define TRUE 1
#define FALSE 0

int main() {
	char op;
	int isRun = TRUE;

	while (isRun) {
		scanf_s("%c%*c", &op,sizeof(op));

		switch (op) {
		case 'a':
			printf("addShare!\n");
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