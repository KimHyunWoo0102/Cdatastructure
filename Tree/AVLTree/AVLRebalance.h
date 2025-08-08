#pragma once

/*BST에 리밸런싱 기능을 추가하여 진행함*/
#include"../BinaryTree/BinaryTree.h"
typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode** pRoot);
BSTData BSTGetNodeData(BTreeNode* bst);

void BSTInsert(BTreeNode** pRoot, BSTData data);

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);

BTreeNode* Rebalance(BTreeNode** pRoot);

int GetHeight(BTreeNode* bst);
int GetHeightDiff(BTreeNode* bst);

BTreeNode* RotateLL(BTreeNode* bst);
BTreeNode* RotateRR(BTreeNode* bst);
BTreeNode* RotateLR(BTreeNode* bst);
BTreeNode* RotateRL(BTreeNode* bst);