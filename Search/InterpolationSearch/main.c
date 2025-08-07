#include<stdio.h>
#include"InterpolSearch.h"

int main() {
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 7);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d", idx);
	return 0;
}