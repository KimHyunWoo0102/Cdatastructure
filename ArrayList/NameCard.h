#pragma once

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct _namecard {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

NameCard* MakeNameCard(const char* name,const char* phone);
void ShowNameCardInfo(const NameCard* pcard);
int NameCompare(NameCard* pcard, const char* name);
void ChangePoineNum(NameCard* pcard, const char* phone);