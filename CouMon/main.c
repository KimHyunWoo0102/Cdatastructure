#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include"Node.h"
#include<stdlib.h>

typedef int Bool;
#define TRUE 1
#define FALSE 0
#define NE 4
#define NG 5

Node *Elements[NE];
Node *Groups[NG];

void initShare();
void traverseShareElements(Group g);
void traverseShareGroup(Element e);
Bool addShare(Element e, Group g);
Bool removeShare(Element e, Group g);

int main() {
    char op, g;
    int isRun = TRUE, e;

    initShare();
    while (isRun) {
        printf("Enter command: ");
        if (scanf(" %c", &op) != 1) {
            printf("Error : invalid input!\n");
            break;
        }

        switch (op) {
        case 'a':
            if (scanf("%d %c", &e, &g) == 2) {
                if (addShare(e, g))
                    printf("OK\n");
                else
                    printf("Error : invalid input!\n");
            }
            else {
                printf("Error : invalid input!\n");
                while (getchar() != '\n'); // flush
            }
            break;

        case 'r':
            if (scanf("%d %c", &e, &g) == 2) {
                if (removeShare(e, g))
                    printf("OK\n");
                else
                    printf("Error method: invalid input!\n");
            }
            else {
                printf("Error scanf : invalid input!\n");
                while (getchar() != '\n'); // flush
            }
            break;

        case 'e':
            if (scanf(" %c", &g) == 1) {
                traverseShareElements(g);
            }
            else {
                printf("Error : invalid input!\n");
                while (getchar() != '\n');
            }
            break;

        case 'g':
            if (scanf("%d", &e) == 1) {
                traverseShareGroup(e);
            }
            else {
                printf("Error : invalid input!\n");
                while (getchar() != '\n');
            }
            break;

        default:
            printf("Error : invalid input!\n");
            isRun = FALSE;
            break;
        }
    }

    return 0;
}

void initShare()
{
	for (int i = 0; i < NE; i++) {
		Elements[i] = makeNode('A' + i, 0);
		Elements[i]->nextElement = NULL;
		Elements[i]->nextGroup = Elements[i];
	}

	for (int i = 0; i < NG; i++) {
		Groups[i] = makeNode(0, 1 + i);
		Groups[i]->nextElement = Groups[i];
		Groups[i]->nextGroup = NULL;
	}
}

void traverseShareElements(Group g)
{
	Node* head = Groups[g - 'A'];
	Node* pNext = head->nextElement;

	while (pNext != head) {
		printf("%d ", pNext->e);
		pNext = pNext->nextElement;
	}
	putchar('\n');
}

void traverseShareGroup(Element e)
{
	Node* head = Elements[e - 1];
	Node* pNext = head->nextGroup;

	while (pNext != head) {
		printf("%c ", pNext->g);
		pNext = pNext->nextGroup;
	}
	putchar('\n');
}

Bool addShare(Element e, Group g)
{
	Node* p = makeNode(e, g);
	Node* HG = Groups[g - 'A'];
	p->nextElement = HG->nextElement;
	HG->nextElement = p;
	Node* HE = Elements[e - 1];
	p->nextGroup = HE->nextGroup;
	HE->nextGroup = p;
	return TRUE;
}

Bool removeShare(Element e, Group g) {
	Node* HG = Groups[g - 'A'], * HE = Elements[e - 1], * rpos;

	while (HG->nextElement != HG && HG->nextElement->e != e) {
		HG = HG->nextElement;
	}
	while (HE->nextGroup != HE && HE->nextGroup->g != g) {
		HE = HE->nextGroup;
	}
	rpos = HG->nextElement;

	HG->nextElement = rpos->nextElement;
	HE->nextGroup = rpos->nextGroup;
	free(rpos);

    return TRUE;
}