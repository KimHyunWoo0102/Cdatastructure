#include "QuickSort.h"
#include<stdio.h>
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}
int findMid(int arr[], int left, int right) {
	int mid = (left + right) / 2;

	if ((arr[left] <= arr[mid] && arr[mid] <= arr[right]) || (arr[right] <= arr[mid] && arr[mid] <= arr[left]))
		return mid;
	if ((arr[mid] <= arr[left] && arr[left] <= arr[right]) || (arr[right] <= arr[left] && arr[left] <= arr[mid]))
		return left;
	if ((arr[left] <= arr[right] && arr[right] <= arr[mid]) || (arr[mid] <= arr[right] && arr[right] <= arr[left]))
		return right;
}
void selectPivot(int arr[], int left, int right) {
	int pivot = findMid(arr, left, right);
	Swap(arr, pivot, left);
}

int Partition(int arr[], int left, int right)
{
	//아무거나 피벗으로 잡음
	//오른쪽 왼쪽 쭈욱 훑으면서 피벗기준으로 큰건 오른쪽 작은건 왼쪽으로 스왑해줌
	//left, right가 1개 차이가 난다면 high 자리에 pivot 스왑해줌
	//이 경우 pivot이 제대로 자리를 찾았으며 피벗기준으로 좌우 나눈뒤에 다시한번 재귀적진행
	selectPivot(arr, left, right);
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	
	printf("피벗 : %d\n", pivot);

	while (low <= high) {
		while (low <= right && arr[low] <= pivot)
			low++;

		while (high >= (left+1) && arr[high] >= pivot)
			high--;

		if (low <= high) {
			Swap(arr, low, high);
		}
	}

	Swap(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left<right) {
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

void QuickSortRun()
{
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	//int arr[3] = { 3,3,3 };
	
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, len - 1);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}
