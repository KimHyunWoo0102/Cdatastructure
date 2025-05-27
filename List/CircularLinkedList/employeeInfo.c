#include "employeeInfo.h"
#include<stdlib.h>
#include<string.h>

void ShowEmployeeInfo(EmployeeInfo* e)
{
	printf("[id : %d, name : %s]\n", e->id, e->name);
}

EmployeeInfo* MakeEmployeeInfo(const int id, const char* name)
{
	EmployeeInfo* newNode = (EmployeeInfo*)malloc(sizeof(EmployeeInfo));
	newNode->id = id;
	strcpy_s(newNode->name, sizeof(newNode->name), name);
	return newNode;
}
