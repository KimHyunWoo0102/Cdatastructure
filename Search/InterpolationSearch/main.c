#include<stdio.h>
#include"InterpolSearch.h"

int main() {
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = ISearch(arr, 1, sizeof(arr) / sizeof(arr[0]) - 1, 0);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε��� : %d", idx);
	return 0;
}