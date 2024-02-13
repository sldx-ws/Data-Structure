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
void ListDestory(ListNode* phead);
void ListClear(ListNode* phead);

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
    ListNode* newNode = BuyListNode(x);
    
    newNode->_prev = phead->_prev;
    phead->_prev = newNode;
    newNode->_next = phead;
}
void ListPopBack(ListNode* phead);

//头插头删
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

//查找（修改）
ListNode* ListFind(ListNode* phead, LTDataType x);

//任意位置插入删除(在pos前面）
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);

//打印
void ListPrint(ListNode* phead)
{
    ListNode* cur = phead->_next;

    while (cur != phead)
    {
        printf("%d<->", cur->_data);
        cur = cur->_next;
    }

    printf("NULL\n");
}
