//#include"ListStack.h"
//#include<stdio.h>
//#include<stdlib.h>
//
//void StackInit(Stack* pstack) {
//	pstack->head = NULL;
//}
//int SIsEmpty(Stack* pstack) {
//	return pstack->head == NULL;
//}
//
//void SPush(Stack* pstack, Data data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->next = pstack->head;
//
//	pstack->head = newNode;
//}
//
//Data SPop(Stack* pstack) {
//	if (SIsEmpty(pstack)) {
//		printf("Stack Memory Error!");
//		exit(-1);
//	}
//
//	Node* rpos = pstack->head;
//	Data Ldata = rpos->data;
//
//	pstack->head = rpos->next;
//	free(rpos);
//	return Ldata;
//}
//
//Data SPeek(Stack* pstack) {
//	if (SIsEmpty(pstack)) {
//		printf("Stack Memory Error!");
//		exit(-1);
//	}
//
//	return pstack->head->data;
//}