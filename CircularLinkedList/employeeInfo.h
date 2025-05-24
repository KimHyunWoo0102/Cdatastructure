#pragma once

typedef struct _employee {
	int id;
	char name[25];
}EmployeeInfo;

void ShowEmployeeInfo(EmployeeInfo* e);

EmployeeInfo* MakeEmployeeInfo(const int id, const char* name);