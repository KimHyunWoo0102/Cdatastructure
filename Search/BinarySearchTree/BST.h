#pragma once
#include"../../Tree/BinaryTree/BinaryTree.h"
typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode** pRoot);
BSTData BSTGetNodeData(BTreeNode* bst);

void BSTInsert(BTreeNode** pRoot, BSTData data);

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);
void BSTShowAll(BTreeNode* bst);

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);