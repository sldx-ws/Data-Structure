#include "BinaryTree.h"

BTNode* CreateNode(int x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;

    return node;
}

void DestroyTree(BTNode* root)
{
    if (root == NULL) return;

    // 后序销毁
    DestroyTree(root->_left);
    DestroyTree(root->_right);
    free(root);
}

void PreOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("%s ", NULL);
        return;
    }    

    printf("%c ", root->_data);
    PreOrder(root->_left);
    PreOrder(root->_right);
}

void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("%s ", NULL);
        return;
    }    

    InOrder(root->_left);
    printf("%c ", root->_data);
    InOrder(root->_right);
}

void PostOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("%s ", NULL);
        return;
    }    

    PostOrder(root->_left);
    PostOrder(root->_right);
    printf("%c ", root->_data);
}

void LevelOrder(BTNode* root)
{
    if (root == NULL) return ;

    Queue q;
    QueueInit(&q);

    QueuePush(&q, root);
    while (!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);

        printf("%c ", front->_data);
        
        if (front->_left)
            QueuePush(&q, front->_left);

        if (front->_right)
            QueuePush(&q, front->_right);
    }

    QueueDestroy(&q);
    printf("\n");
}

int TreeSize(BTNode* root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}

int LeafSize(BTNode* root)
{
    if (root == NULL)
        return 0;

    if (root->_left == NULL && root->_right == NULL)
        return 1;

    return LeafSize(root->_left) + LeafSize(root->_right);
}

int TreeLevelKsize(BTNode* root, int k)
{
    if (root == NULL) return 0;
    if (k == 1) return 1;

    return TreeLevelKsize(root->_left, k - 1)
        + TreeLevelKsize(root->_right, k - 1);
}

BTNode* Find(BTNode* root, BTDataType x)
{
    if (root == NULL) return NULL;
    if (root->_data == x) return root;

    BTNode* node = Find(root->_left, x);
    if (node) return node;
    
    node = Find(root->_right, x);
    if (node) return node;

    return NULL;
}

bool isCompleteBinaryTree(BTNode* root)
{
    if (root == NULL)
        return true;

    Queue q;
    QueueInit(&q);

    QueuePush(&q, root);

    while(!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);

        if (front == NULL) break;

        QueuePush(&q, front->_left);
        QueuePush(&q, front->_right);
    }

    while(!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);

        if (front)
        {
            QueueDestroy(&q);
            return false;
        }
    }

    return true;
}