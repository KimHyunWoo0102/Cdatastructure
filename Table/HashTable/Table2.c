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
		printf("Key 중복 Error!\n");
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
    return k % 100; // 단순 해시
}

// 해시 테이블 전체 데이터 출력 함수
void PrintAllTableData(Table* pt) {
    Slot cSlot;
    printf("\n===== 전체 테이블 데이터 출력 =====\n");
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

    // 테이블 초기화
    TBLInit(&myTbl, MyHashFunc);

    // 데이터 삽입
    np = MakePersonData(900254, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900139, "Kim", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900827, "Park", "Kwangju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(100827, "Park2", "Kwangju");
    TBLInsert(&myTbl, GetSSN(np), np);

    // 중복 키 삽입 시도
    np = MakePersonData(900254, "Lee-Dup", "Busan");
    TBLInsert(&myTbl, GetSSN(np), np); // "Key 중복 Error!" 출력 예상

    // 데이터 조회 테스트
    printf("\n===== 개별 검색 테스트 =====\n");
    sp = TBLSearch(&myTbl, 900254);
    if (sp != NULL) ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900139);
    if (sp != NULL) ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900827);
    if (sp != NULL) ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 100827);
    if (sp != NULL) ShowPerInfo(sp);
    // 존재하지 않는 데이터 검색
    sp = TBLSearch(&myTbl, 999999);
    if (sp == NULL) printf("999999: 데이터 없음\n");

    // 삭제 테스트
    printf("\n===== 삭제 테스트 =====\n");
    rp = TBLDelete(&myTbl, 900139); // Kim 삭제
    if (rp != NULL) {
        printf("삭제된 데이터: ");
        ShowPerInfo(rp);
        free(rp); // 동적 메모리 해제
    }

    rp = TBLDelete(&myTbl, 123456); // 없는 데이터 삭제
    if (rp == NULL) {
        printf("123456: 삭제할 데이터 없음\n");
    }

    // 전체 출력
    PrintAllTableData(&myTbl);

    // 남은 데이터 메모리 해제
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