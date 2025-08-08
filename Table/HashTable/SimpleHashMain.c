#include"SimpleHashMain.h"

void run() {
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, MyHashFunc);

	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = MakePersonData(20130012, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(sp), sp);

	rp = MakePersonData(20170049, "Han", "Kwangwon");
	TBLInsert(&myTbl, GetSSN(rp), rp);

	sp = TBLSearch(&myTbl, 20120003);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 20130012);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 20170049);
	if (sp != NULL)
		ShowPerInfo(sp);


	rp = TBLDelete(&myTbl, 20120003);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 20130012);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 20170049);
	if (rp != NULL)
		free(rp);
}

int MyHashFunc(int k)
{
	return k % 100;
}