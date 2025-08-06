#include "MergeSort.h"
#include<stdio.h>
#include<stdlib.h>


void MergeSort(int arr[], int left, int right)
{
	//���� ���� : 2���� ���´ٸ� ���� ó��
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		Merge(arr, left, mid, right);
	}

}

void Merge(int arr[], int left, int mid, int right)
{
	//arr�� left���� mid����  
	//mid+1���� right ���� �ϳ��� ���ذ��� ���ο� �迭�� �ֱ�

	int leftPivot = left;
	int rightPivot = mid + 1;

	int* copyArr = (int*)malloc(sizeof(int) * (right - left+1));
	int i = 0;

	while ((leftPivot <= mid) && (rightPivot <= right)) {
		if (arr[leftPivot] > arr[rightPivot]) {
			copyArr[i] = arr[rightPivot];
			rightPivot++, i++;
		}
		else {
			copyArr[i] = arr[leftPivot];
			leftPivot++, i++;
		}
	}

	if (leftPivot > mid)
	{
		for (int idx = rightPivot; idx <= right; idx++, i++) {
			copyArr[i] = arr[idx];
		} 
	}
	else {
		for (int idx = leftPivot; idx <= mid; idx++, i++)
			copyArr[i] = arr[idx];
	}

	for (int i = left; i <= right; i++) {
		arr[i] = copyArr[i - left];
	}

	free(copyArr);
}

void MergeSortRun()
{
	int arr[] = { 5, 3, 8, 4, 2, 7, 1, 6 };

	int arrLen = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, 0, arrLen -1);

	for (int i = 0; i < arrLen; i++)
		printf("%d ", arr[i]);
}

