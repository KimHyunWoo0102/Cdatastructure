#pragma once

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _nodeStack {
	Data data;
	struct _nodeStack* next;
}Node;

typedef struct _lq {
	Node* rear;
	Node* front;
}LinkedQueue;

typedef LinkedQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);