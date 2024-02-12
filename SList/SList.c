#include "SList.h"

// 申请节点
SListNode* BuySListNode(SListDataType x)
{
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    if (newNode == NULL)
    {
        printf("申请节点失败\n");
        exit(0);
    }

    newNode->_data = x;
    newNode->_next = NULL;
    
    return newNode;
}

// 尾插尾删 
void SListPushBack(SListNode** pphead, SListDataType x)
{

    SListNode* newNode = BuySListNode(x);

    if (*pphead == NULL)
    {
        *pphead = newNode; 
    }
    else 
    {
        SListNode* tail = *pphead;
        while (tail->_next)
        {
            tail = tail->_next; 
        }

        tail->_next = newNode;
    }
}

void SListPopBack(SListNode** pphead)
{
    assert(*pphead);

    if ((*pphead)->_next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    else 
    {
        SListNode* prev = NULL;
        SListNode* tail = *pphead;
        
        while (tail->_next)
        {
            prev = tail;
            tail = tail->_next;
        }

        free(tail);
        prev->_next = NULL;
    }
}

// 头插头删
void SListPushFront(SListNode** pphead, SListDataType x)
{
    SListNode* newNode = BuySListNode(x);
    
    newNode->_next = *pphead;
    *pphead = newNode;
}

void SListPopFront(SListNode** pphead)
{
    assert(*pphead);

    SListNode* cur = *pphead;
    *pphead = (*pphead)->_next;
    free(cur);
}

void SListPrint(SListNode* phead)
{
    SListNode* cur = phead;
    while (cur)
    {
        printf("%d -> ", cur->_data);
        cur = cur->_next;
    }

    printf("NULL\n");
}

// 查找
SListNode* SListFind(SListNode* phead, SListDataType x)
{
    SListNode* cur = phead;

    while (cur)
    {
        if (cur->_data == x)
        {
            printf("find success\n");
            return cur;
        }
        
        cur = cur->_next;
    }

    printf("find failed\n");
    return NULL;
}

// 指定位置之后插入删除
void SListInsertAfter(SListNode* pos, SListDataType x)
{
    assert(pos);

    SListNode* newNode = BuySListNode(x);

    newNode->_next = pos->_next;
    pos->_next = newNode;
}

void SListEraseAfter(SListNode* pos)
{
    assert(pos);

    if (pos->_next)
    {
        SListNode* next = pos->_next;
        pos->_next = next->_next;
        free(next);
    }
}
