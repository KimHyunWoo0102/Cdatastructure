#pragma once

typedef int Key;
typedef double Data;
typedef struct item {
	Key searchKey;
	Data searchData;
}Item;

int ISearch(int arr[], int first, int last, int target);