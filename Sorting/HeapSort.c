#include "HeapSort.h"
#include<stdio.h>

int Pricomp(int n1, int n2)
{
    return n2 - n1;
}

void HeapSort(int arr[], int n, PriorityComp pr)
{
    Heap heap;
    HeapInit(&heap, pr);

    for (int i = 0; i < n; i++)
        HInsert(&heap, arr[i]);

    for (int i = 0; i < n; i++)
        arr[i] = HDelete(&heap);
}

void HeapSortRun()
{
    int arr[4] = { 3,4,2,1 };
    HeapSort(arr, sizeof(arr) / sizeof(arr[0]), Pricomp);

    for (int i = 0; i < 4; i++)
        printf("%d ", arr[i]);
}


