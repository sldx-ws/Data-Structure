#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BTNode
{
    BTDataType _data;
    struct BTNode* _left;
    struct BTNode* _right;
} BTNode;

BTNode* CreateNode(int x);
void DestoryTree(BTNode* root);
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
int TreeSize(BTNode* root);
int LeafSize(BTNode* root);
int TreeLevelKsize(BTNode* root, int k); // 第k层节点个数
BTNode* Find(BTNode* root, BTDataType x);