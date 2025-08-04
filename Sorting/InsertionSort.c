#include "InsertionSort.h"
#include<stdio.h>

void InserSort(int arr[], int n)
{
	int i, j;
	for (i = 1; i < n; i++) {
		int insertData = arr[i];
		for (j = i-1; j >=0; j--) {
			if (arr[j] > insertData) {
				arr[j + 1] = arr[j];
			}
			else break;
		}

		arr[j + 1] = insertData;
	}
}

void InserSortRun()
{
	int arr[4] = { 3,2,4,1 };
	InserSort(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
}
