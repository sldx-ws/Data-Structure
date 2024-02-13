#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
    LTDataType _data;
    struct ListNode* _prev;
    struct ListNode* _next;
} ListNode;

//两种初始化
void ListInit1(ListNode** pphead);
ListNode* ListInit2();

//释放
void ListDestory(ListNode* phead);
void ListClear(ListNode* phead);

ListNode* BuyListNode(LTDataType x);

//尾插尾删
void ListPushBack(ListNode* phead, LTDataType x);
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
void ListPrint(ListNode* phead);
