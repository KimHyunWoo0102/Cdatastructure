#include"BubbleSort.h"
#include<stdio.h>

void BubbleSort(int arr[], int n) {
	for (int i = n-1; i >=0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void BubbleSortRun() {
	int arr[4] = { 3,2,4,1 };
	
	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
}


