#pragma once

#include"../List/LinkedList/LinkedList.h"

enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _val {
	int numV;
	int numE;
	List* adjList;
}ALGragh;

void GraphInit(ALGragh* pg, int nv);

void GraphDestroy(ALGragh* pg);
void AddEdge(ALGragh* pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGragh* pg);