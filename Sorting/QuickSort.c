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
	//�ƹ��ų� �ǹ����� ����
	//������ ���� �޿� �����鼭 �ǹ��������� ū�� ������ ������ �������� ��������
	//left, right�� 1�� ���̰� ���ٸ� high �ڸ��� pivot ��������
	//�� ��� pivot�� ����� �ڸ��� ã������ �ǹ��������� �¿� �����ڿ� �ٽ��ѹ� ���������
	selectPivot(arr, left, right);
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	
	printf("�ǹ� : %d\n", pivot);

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
