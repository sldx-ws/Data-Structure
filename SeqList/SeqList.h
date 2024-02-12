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
}SL, SeqList;

// 初始化
void SeqListInit(SL* ps);

// 检查容量
void SeqListCheckCapacity(SL* ps);

// 尾插尾删 头插头删
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

// 任意位置插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

// print
void Print(SL* ps);

// 查找
int SeqListFind(SL* ps, SLDataType x);
