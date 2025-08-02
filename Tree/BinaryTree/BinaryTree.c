#include "BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>

BTreeNode* MakeBTreeNode(void)
{
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

BTData GetData(BTreeNode* bt)
{
    return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->left != NULL)
        DeleteTree(main->left);
    main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->right != NULL)
        DeleteTree(main->right);
    main->right = sub;
}

void DeleteTree(BTreeNode* bt)
{
    if (bt->left != NULL) {
        DeleteTree(bt->left);
        bt->left = NULL;
    }
    if (bt->right != NULL) {
        DeleteTree(bt->right);
        bt->right = NULL;
    }
    free(bt);
}
