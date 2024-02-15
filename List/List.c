#include "List.h"

//两种初始化
void ListInit1(ListNode** pphead)
{
   ListNode* newNode = BuyListNode(0);
   *pphead = newNode;
   (*pphead)->_prev = newNode;
   (*pphead)->_next = newNode;
}

ListNode* ListInit2()
{
   ListNode* phead = BuyListNode(0);
   phead->_prev = phead;
   phead->_next = phead;

   return phead;
}

//释放
void ListDestory(ListNode* phead)
{
    assert(phead);

    ListClear(phead);
    free(phead);
}

void ListClear(ListNode* phead)
{
    assert(phead);

    //清理所有数据节点，保留头节点，可以继续使用
    ListNode* cur = phead->_next;
    while (cur != phead)
    {
        ListNode* next = cur->_next;
        free(cur);
        cur = next;
    }

    phead->_prev = phead;
    phead->_next = phead;
}

ListNode* BuyListNode(LTDataType x)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL)
    {
        printf("申请节点失败\n");
        exit(-1);
    }

    newNode->_data = x;
    newNode->_prev = NULL;
    newNode->_next = NULL;

    return newNode;
}

//尾插尾删
void ListPushBack(ListNode* phead, LTDataType x)
{
    assert(phead);

    ListNode* newNode = BuyListNode(x);
    
    phead->_prev->_next = newNode;
    newNode->_prev = phead->_prev;
    phead->_prev = newNode;
    newNode->_next = phead;
}

void ListPopBack(ListNode* phead)
{
    assert(phead);

    ListNode* tail = phead->_prev;

    tail->_prev->_next = phead;
    phead->_prev = tail->_prev;

    free(tail);
}

//头插头删
void ListPushFront(ListNode* phead, LTDataType x)
{
    assert(phead);

    ListNode* newNode = BuyListNode(x);

    newNode->_next = phead->_next;
    newNode->_prev = phead;

    phead->_next->_prev = newNode;
    phead->_next = newNode;
}

void ListPopFront(ListNode* phead)
{
    assert(phead);
    assert(phead->_next != phead);

    ListNode* first = phead->_next;

    phead->_next = first->_next;
    first->_next->_prev = phead;

    free(first);
}

//查找（修改）
ListNode* ListFind(ListNode* phead, LTDataType x)
{
    assert(phead);

    ListNode* cur = phead->_next;
    while (cur != phead)
    {
        if (cur->_data == x)
            return cur;
        
        cur = cur->_next;
    }

    return NULL;
}

//任意位置插入(在pos前面）、删除
void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);

    ListNode* newNode = BuyListNode(x);
    ListNode* posPrev = pos->_prev;

    newNode->_next = pos;
    newNode->_prev = posPrev;

    posPrev->_next = newNode;
    pos->_prev = newNode;
}

void ListErase(ListNode* pos)
{
    assert(pos);

    ListNode* posPrev = pos->_prev;
    ListNode* posNext = pos->_next;

    posPrev->_next = posNext;
    posNext->_prev = posPrev;

    free(pos);
}

//打印
void ListPrint(ListNode* phead)
{
    assert(phead);
    assert(phead->_next != phead);

    ListNode* cur = phead->_next;

    while (cur != phead)
    {
        printf("%d<->", cur->_data);
        cur = cur->_next;
    }
    
    printf("\n");
}
