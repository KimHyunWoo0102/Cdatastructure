#include "ArrayList.h"
#include<stdio.h>

void PrintList() {
	for (int i = 0; i < g_List.size; i++) {
		printf("[idx :\t%d ,\tdata :\t%d]\n",i, g_List.arr[i]);
	}
}

void Add(int idx, LData data) {
	if (g_List.size == MAX_SIZE) 
		printf("Error : full list exception\n");
	

	if (idx < 0 || idx > g_List.size)
		printf("Error : invalid index exception\n");

	for (int i = g_List.size - 1; i >= idx; i--) 
		g_List.arr[i + 1] = g_List.arr[i];

	g_List.arr[idx] = data;
	g_List.size++;
}