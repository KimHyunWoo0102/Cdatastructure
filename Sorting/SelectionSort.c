#include "SelectionSort.h"
#include<stdio.h>
#include<limits.h>

void SelSort(int arr[], int n)
{
	int min = 0;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min] > arr[j])
				min = j;
		}

		{
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}

void SelSortRun()
{
	int arr[4] = { 3,2,4,1 };

	SelSort(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
}
