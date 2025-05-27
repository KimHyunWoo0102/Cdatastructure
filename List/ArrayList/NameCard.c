#include "NameCard.h"
#include<stdlib.h>
#include<string.h>

NameCard* MakeNameCard(const char* name, const char* phone)
{
    NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));
    strcpy_s(newCard->name, sizeof(newCard->name), name);
    strcpy_s(newCard->phone, sizeof(newCard->phone), phone);
    return newCard;
}

void ShowNameCardInfo(const NameCard* pcard)
{
    printf("[%s : %s]\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard* pcard, const char* name)
{
    return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard* pcard, const char* phone)
{
    strcpy_s(pcard->phone, sizeof(pcard->phone), phone);
}
