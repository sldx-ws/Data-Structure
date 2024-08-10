#include "BinaryTree.h"

BTNode* CreateBinaryTree()
{
    BTNode* A = CreateNode('A');
    BTNode* B = CreateNode('B');
    BTNode* C = CreateNode('C');
    BTNode* D = CreateNode('D');
    BTNode* E = CreateNode('E');
    A->_left = B;
    A->_right = C;
    B->_left = D;
    B->_right = E;

    return A;
}

void test01()
{
    BTNode* root = CreateBinaryTree();
    // PreOrder(root);
    InOrder(root);
    // PostOrder(root);

    // int tree = TreeSize(root);
    // printf("TreeSize: %d\n", tree);

    // int leaf = LeafSize(root);
    // printf("LeafSize: %d\n", leaf);
}

void test02()
{
    BTNode* root = CreateBinaryTree();
    
    int n = TreeLevelKsize(root, 2);
    printf("level2: %d\n", n);

    BTNode* ret = Find(root, 'B');
    printf("findB: %c\n", ret->_data);
}

void test03_LevelOrder()
{
    BTNode* root = CreateBinaryTree();
    LevelOrder(root);
}

void test04_isComplete()
{
    // BTNode* root = CreateBinaryTree();
    // bool ret1 = isCompleteBinaryTree(root);
    // printf("%d\n", ret1);

    BTNode* A = CreateNode('A');
    BTNode* B = CreateNode('B');
    BTNode* C = CreateNode('C');
    BTNode* E = CreateNode('E');
    A->_left = B;
    A->_right = C;
    B->_right = E;
    bool ret2 = isCompleteBinaryTree(A);
    printf("%d\n", ret2);
}

int main()
{
    // test01();
    // test02();
    // test03_LevelOrder();
    test04_isComplete();

    return 0;
}