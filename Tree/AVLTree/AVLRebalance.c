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
		return NULL;    // Ű�� �ߺ��� ������� �ʴ´�. 
	}
	return *pRoot;
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
		return rightH + 1;//�������� ������ �������� �ϳ��� ����?
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
	//��� ���Ұ����� ���� �� �׳� ���°� �������� ã�Ƽ� ����
	BTreeNode* pNode;
	BTreeNode* cNode;

	if (bst == NULL)
		return NULL;

	pNode = bst;
	cNode = GetLeftSubTree(bst);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));//pNode�� ������ cNode�� �������̶� ��ü
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

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));//pNode�� ������ cNode�� �������̶� ��ü
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
	//bst�� �ùٷ� ���Դٰ� ���� 
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
	//bst�� �ùٷ� ���Դٰ� ���� 
	cNode = RotateLL(cNode);
	return RotateRR(pNode);
}
