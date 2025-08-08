#include "Table2.h"
#include<stdio.h>

void TBLInit(Table* pt, HashFunc f)
{
	for (int i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));

	pt->hf = f;
}

void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k);
	Slot ns = { k,v };

	if (TBLSearch(pt, k) != NULL) {
		printf("Key �ߺ� Error!\n");
		return;
	}

	LInsert(&(pt->tbl[hv]), ns);
}

Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot)) {
		if (cSlot.key == k) {
			LRemove(&(pt->tbl[hv]));
			return cSlot.val;
		}
		else {
			while (LNext(&(pt->tbl[hv]), &cSlot)) {
				if(cSlot.key==k) {
					LRemove(&(pt->tbl[hv]));
					return cSlot.val;
				}
			}
		}
	}
	return NULL;
}

Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot)) {
		if (cSlot.key == k) {
			return cSlot.val;
		}
		else {
			while (LNext(&(pt->tbl[hv]), &cSlot)) {
				if (cSlot.key == k) {
					return cSlot.val;
				}
			}
		}
	}
	return NULL;
}

int MyHashFunc(int k) {
    return k % 100; // �ܼ� �ؽ�
}

// �ؽ� ���̺� ��ü ������ ��� �Լ�
void PrintAllTableData(Table* pt) {
    Slot cSlot;
    printf("\n===== ��ü ���̺� ������ ��� =====\n");
    for (int i = 0; i < MAX_TBL; i++) {
        if (LFirst(&(pt->tbl[i]), &cSlot)) {
            printf("[Bucket %d]\n", i);
            ShowPerInfo(cSlot.val);
            while (LNext(&(pt->tbl[i]), &cSlot)) {
                ShowPerInfo(cSlot.val);
            }
        }
    }
    printf("=================================\n");
}

void run() {
    Table myTbl;
    Person* np;
    Person* sp;
    Person* rp;

    // ���̺� �ʱ�ȭ
    TBLInit(&myTbl, MyHashFunc);

    // ������ ����
    np = MakePersonData(900254, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900139, "Kim", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900827, "Park", "Kwangju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(100827, "Park2", "Kwangju");
    TBLInsert(&myTbl, GetSSN(np), np);

    // �ߺ� Ű ���� �õ�
    np = MakePersonData(900254, "Lee-Dup", "Busan");
    TBLInsert(&myTbl, GetSSN(np), np); // "Key �ߺ� Error!" ��� ����

    // ������ ��ȸ �׽�Ʈ
    printf("\n===== ���� �˻� �׽�Ʈ =====\n");
    sp = TBLSearch(&myTbl, 900254);
    if (sp != NULL) ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900139);
    if (sp != NULL) ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900827);
    if (sp != NULL) ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 100827);
    if (sp != NULL) ShowPerInfo(sp);
    // �������� �ʴ� ������ �˻�
    sp = TBLSearch(&myTbl, 999999);
    if (sp == NULL) printf("999999: ������ ����\n");

    // ���� �׽�Ʈ
    printf("\n===== ���� �׽�Ʈ =====\n");
    rp = TBLDelete(&myTbl, 900139); // Kim ����
    if (rp != NULL) {
        printf("������ ������: ");
        ShowPerInfo(rp);
        free(rp); // ���� �޸� ����
    }

    rp = TBLDelete(&myTbl, 123456); // ���� ������ ����
    if (rp == NULL) {
        printf("123456: ������ ������ ����\n");
    }

    // ��ü ���
    PrintAllTableData(&myTbl);

    // ���� ������ �޸� ����
    for (int i = 0; i < MAX_TBL; i++) {
        Slot cSlot;
        if (LFirst(&(myTbl.tbl[i]), &cSlot)) {
            free(cSlot.val);
            while (LNext(&(myTbl.tbl[i]), &cSlot)) {
                free(cSlot.val);
            }
        }
    }
}