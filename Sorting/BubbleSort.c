#include"BubbleSort.h"
#include<stdio.h>

void BubbleSort(int arr[], int n) {
	for (int i = n-1; i >=0; i--) {//n-1,n-2,....1,0 n회 반복
		for (int j = 0; j < i; j++) {//1,2,3,4,...n-1 (n-1)(n)/2 회 반복
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


