#include "ALGraphBFS.h"
#include"../Queue/LinkedQueue/ListBaseQueue.h"
#include<stdlib.h>
#include<stdio.h>
#include<memory.h>
#include <malloc.h>

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

    pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
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

    if (pg->visitInfo != NULL)
        free(pg->visitInfo);
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

void BFShowGraphVertex(ALGraph* pg, int startV)
{
    Queue queue;
    QueueInit(&queue);

    int visitV = startV;
    int nextV;

    VisitVertex(pg, visitV);
    
    while (LFirst(&pg->adjList[visitV], &nextV) == TRUE) {
        if (VisitVertex(pg, nextV) == TRUE)
            Enqueue(&queue, nextV);

        while (LNext(&(pg->adjList[visitV]), &nextV)) {
            if (VisitVertex(pg, nextV) == TRUE) {
                Enqueue(&queue, nextV);
            }
        }

        if (QIsEmpty(&queue))
            break;
        else
            visitV = Dequeue(&queue);
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

int VisitVertex(ALGraph* pg, int visitV) {
    if (pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] = 1;
        printf("%c ", visitV + 'A');
        return TRUE;
    }
    return FALSE;
}


int WhoIsPrecede(int data1, int data2) {
    return data1 < data2 ? FALSE : TRUE;
}