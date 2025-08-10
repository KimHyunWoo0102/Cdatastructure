#pragma once

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _nodeStack {
	Data data;
	struct _nodeStack* next;
}NodeQ;

typedef struct _lq {
	NodeQ* rear;
	NodeQ* front;
}LinkedQueue;

typedef LinkedQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);