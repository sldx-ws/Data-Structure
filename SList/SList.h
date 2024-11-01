#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SListDataType;

typedef struct SListNode
{
    SListDataType _data;
    struct SListNode* _next;
} SListNode;

// 尾插尾删
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);

// 头插头删
void SListPushFront(SListNode** pphead, SListDataType x);
void SListPopFront(SListNode** pphead);

void SListPrint(SListNode* phead);

// 查找
SListNode* SListFind(SListNode* phead, SListDataType x);

// 指定位置之后插入删除
void SListInsertAfter(SListNode* pos, SListDataType x);
void SListEraseAfter(SListNode* pos);
