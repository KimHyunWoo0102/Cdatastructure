#pragma once

#define MAX_SIZE 101
#define LData int


typedef struct ArrayList {
	int size;
	LData arr[MAX_SIZE];
}ArrayList;

typedef ArrayList List;

List g_List;

void PrintList();
void Add(int idx, LData data);
