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

int main()
{
    BTNode* root = CreateBinaryTree();
    // PreOrder(root);
    // PostOrder(root);

    // int tree = TreeSize(root);
    // printf("TreeSize: %d\n", tree);

    int leaf = LeafSize(root);
    printf("LeafSize: %d\n", leaf);

    return 0;
}