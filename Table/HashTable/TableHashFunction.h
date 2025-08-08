#pragma once

typedef struct _empInfo {
	int empNum;
	int age;
}EmpInfo;

int GetHashValue(int empNum);
void run();