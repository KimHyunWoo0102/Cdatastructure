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
	//1. ���� ���� ������ �ִ°� NULL�̸� ����
	//2. ���� ����� �����Ϳ� ���ٸ� ���� ��� ��ȯ
	//3. �۴ٸ� ���� ũ�ٸ� ���������� ���
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
			dcNode = GetLeftSubTree(dNode);//���ʸ� �����Ѵٸ� ���� ����Ʈ���� ���ܿ���
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
	
		if (GetLeftSubTree(mpNode) == mNode)//���� ����� ���ʿ��� �����´ٸ�
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));//������ ������ NULL���״� ���������� ���� �������� �ִٸ� �����۵� ���ٸ� NULL
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)//��Ʈ ��尡 �����Ǽ� ó�� pVRoot�� �������� ���� pRoot�� �ƴ϶��
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
