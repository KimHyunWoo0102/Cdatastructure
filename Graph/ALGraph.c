#include "ALGraph.h"
#include<stdio.h>
#include<stdlib.h>
#include "ALGraphDFS.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph* pg, int nv)
{
	pg->adjList = (List*)malloc(sizeof(List) * nv);

	pg->numV = nv;
	pg->numE = 0;

	for (int i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

void GraphDestroy(ALGraph* pg)
{
    if (pg->adjList != NULL) {
        // �� ������ ���� ����Ʈ �޸� ����
        for (int i = 0; i < pg->numV; i++) {
            LData data;
            if (LFirst(&(pg->adjList[i]), &data)) {
                LRemove(&(pg->adjList[i]));
                while (LNext(&(pg->adjList[i]), &data)) {
                    LRemove(&(pg->adjList[i]));
                }
            }
        }
        free(pg->adjList);
        pg->adjList = NULL;
    }
}


void AddEdge(ALGraph* pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);

    pg->numE++;
}

void ShowGraphEdgeInfo(ALGraph* pg)
{
    int vx;

    for (int i = 0; i < pg->numV; i++) {
        printf("%c�� ����� ����: ", i + 'A');

        if (LFirst(&pg->adjList[i], &vx)) {
            printf("%c ", vx + 'A');

            while (LNext(&pg->adjList[i], &vx))
                printf("%c ", vx + 'A');
        }

        printf("\n");
    }
}


int WhoIsPrecede(int data1, int data2) {
    return data1 < data2 ? FALSE : TRUE;
}