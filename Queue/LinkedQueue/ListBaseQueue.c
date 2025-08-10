#include"ListBaseQueue.h"
#include<stdio.h>
#include<stdlib.h>

void QueueInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue* pq) {
	if (pq->front == NULL)
		return TRUE;
	else return FALSE;
}

void Enqueue(Queue* pq, Data data) {
	NodeQ* newNode = (NodeQ*)malloc(sizeof(NodeQ));
	newNode->data = data;
	newNode->next = NULL;

	if (QIsEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Empty Queue Error!");
		exit(-1);
	}

	NodeQ* rpos = pq->front;
	Data rdata = pq->front->data;

	pq->front = pq->front->next;
	free(rpos);
	return rdata;
}
Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Empty Queue Error!");
		exit(-1);
	}

	return pq->front->data;
}