#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include"Node.h"

typedef int Bool;
#define TRUE 1
#define FALSE 0
#define NE 4
#define NG 5

Node Elements[NE];
Node Groups[NG];

void initShare();
void traverseShareElements(Group g);
void traverseShareGroup(Element e);
Bool addShare(Element e, Group g);
Bool removeShare(Element e, Group g);

int main() {
	char op;
	Group g;
	Element e;
	int isRun = TRUE;

	initShare();

	while (isRun) {
		scanf(" %c", &op);

		switch (op) {
		case 'a':
			scanf("%d %c", &e, &g);
			if (addShare(e, g)) 
				printf("OK\n");
			else
				printf("Error : invalid input!\n");
			break;
		case 'r':
			scanf("%d %c", &e, &g);
			if (removeShare(e, g))
				printf("OK\n");
			else
				printf("Error : invalid input!\n");
			break;
		case 'e':
			scanf(" %c", &g);
			traverseShareElements(g);
			break;
		case 'g':
			scanf("%d", &e);
			traverseShareGroup(e);
			break;
		default:
			printf("error : invalid input!\n");
			isRun = FALSE;
			break;
		}
	}
}