#include "BST.h"
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
	BTreeNode* newNode = MakeBTreeNode();
	SetData(newNode, data);

	BTreeNode* cNode = *pRoot;
	BTreeNode* pNode = NULL;

	if (*pRoot == NULL) {
		*pRoot = newNode;
		return;
	}
	else {
		while (cNode != NULL) {
			if (cNode->data < data) {
				pNode = cNode;
				cNode = cNode->right;
			}
			else {
				pNode = cNode;
				cNode = cNode->left;
			}
		}

		if (pNode->data < data) {
			MakeRightSubTree(pNode, newNode);
		}
		else {
			MakeLeftSubTree(pNode, newNode);
		}
	}
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
