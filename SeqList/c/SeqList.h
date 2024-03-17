#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 动态顺序表（大小可变）
typedef  int  SLDataType;

typedef struct SeqList
{
    SLDataType* _a;
    int _size;      // 有效数据个数    
    int _capacity;  // 容量 
} SeqList;

// 初始化 销毁
void SeqListInit(SeqList* psl);
void SeqListDestory(SeqList* psl);

// 尾插尾删 头插头删
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

// 任意位置插入删除
void SeqListInsert(SeqList* psl, int pos, SLDataType x);
void SeqListErase(SeqList* psl, int pos);

// print
void Print(SeqList* psl);

// 查找（返回下标）
int SeqListFind(SeqList* psl, SLDataType x);
