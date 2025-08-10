#pragma once

#include"../List/LinkedList/LinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct {
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
}ALGraph;

void GraphInit(ALGraph* pg, int nv);
void GraphDestroy(ALGraph* pg);

void AddEdge(ALGraph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph* pg);
void BFShowGraphVertex(ALGraph* pg, int startV);
