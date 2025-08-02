#include<stdio.h>
#include"CircularQueue.h"

int main() {
	Queue queue;

	QueueInit(&queue);
	
	Enqueue(&queue, 1); Enqueue(&queue, 2);
	Enqueue(&queue, 3); Enqueue(&queue, 4);
	Enqueue(&queue, 5);

	while (!QIsEmpty(&queue)) {
		printf("%d ", Dequeue(&queue));
	}
}