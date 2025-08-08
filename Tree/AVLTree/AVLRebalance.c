#include "AVLRebalance.h"
#include<stdio.h>
#include<stdlib.h>

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return bst->data;
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	if (*pRoot == NULL)
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return NULL;    // 키의 중복을 허용하지 않는다. 
	}
	return *pRoot;
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	//1. 만약 현재 가지고 있는게 NULL이면 종료
	//2. 현재 노드의 데이터와 같다면 현재 노드 반환
	//3. 작다면 왼쪽 크다면 오른쪽으로 재귀
	if (bst == NULL)
		return NULL;
	else if (bst->data == target)
		return bst;
	else if (bst->data > target)
		return BSTSearch(bst->left, target);
	else
		return BSTSearch(bst->right, target);
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode();
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if (target < GetData(pNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	if (!GetLeftSubTree(dNode) && !GetRightSubTree(dNode))
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	else if (!GetLeftSubTree(dNode) || !GetRightSubTree(dNode)) {
		BTreeNode* dcNode;

		if (GetLeftSubTree(dNode))
			dcNode = GetLeftSubTree(dNode);//왼쪽만 존재한다면 왼쪽 서브트리를 땡겨오기
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	else {
		BTreeNode* mNode = GetRightSubTree(dNode);
		BTreeNode* mpNode = dNode;
		int delData = 0;

		while (GetLeftSubTree(mNode)) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, mNode->data);

		if (GetLeftSubTree(mpNode) == mNode)//이전 노드의 왼쪽에서 가져온다면
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));//어차피 왼쪽은 NULL일테니 오른쪽으로 대입 오른쪽이 있다면 정상작동 없다면 NULL
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)//루트 노드가 삭제되서 처음 pVRoot의 오른쪽이 원래 pRoot가 아니라면
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	*pRoot=Rebalance(pRoot);
	return dNode;
}

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}

BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;
	if (bt != NULL)
	{
		delNode = bt->left;
		bt = bt->left;
	}
	return delNode;
}

BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;
	if (bt != NULL)
	{
		delNode = bt->left;
		bt = bt->left;
	}
	return delNode;
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);

	if (hDiff > 1) {
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)//LL
			*pRoot = RotateLL(*pRoot);
		else//LR
			*pRoot = RotateLR(*pRoot);
	}

	if (hDiff < -1) {
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)//RR
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot;
}

int GetHeight(BTreeNode* bst)
{
	int leftH;
	int rightH;

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;//같을때는 무조건 오른쪽이 하나더 증가?
}

int GetHeightDiff(BTreeNode* bst)
{
	int lsh;
	int rsh;

	if (bst == NULL)
		return 0;
	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh;
}

BTreeNode* RotateLL(BTreeNode* bst)
{
	//어디가 변할건지는 몰라도 됌 그냥 들어온거 기준으로 찾아서 돌려
	BTreeNode* pNode;
	BTreeNode* cNode;

	if (bst == NULL)
		return NULL;

	pNode = bst;
	cNode = GetLeftSubTree(bst);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));//pNode의 왼편을 cNode의 오른쪽이랑 교체
	ChangeRightSubTree(cNode, pNode);
	return cNode;
}

BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	if (bst == NULL)
		return NULL;

	pNode = bst;
	cNode = GetRightSubTree(bst);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));//pNode의 왼편을 cNode의 오른쪽이랑 교체
	ChangeLeftSubTree(cNode, pNode);
	return cNode;
}

BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	if (bst == NULL)
		return NULL;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);
	//bst는 올바로 들어왔다고 가정 
	cNode = RotateRR(cNode);
	return RotateLL(pNode);
}

BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode;
	BTreeNode* cNode;

	if (bst == NULL)
		return NULL;

	pNode = bst;
	cNode = GetRightSubTree(pNode);
	//bst는 올바로 들어왔다고 가정 
	cNode = RotateLL(cNode);
	return RotateRR(pNode);
}
