#pragma once 

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#ifdef __BINARYTREE_H__
    struct BTNode;  // 声明二叉树节点
    typedef struct BTNode* QDataType;
#else
    typedef int QDataType;
#endif

typedef struct QueueNode
{
    QDataType _data;
    struct QueueNode* _next;
} QueueNode;

typedef struct Queue 
{
    QueueNode* _head;
    QueueNode* _tail;
} Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
size_t QueueSize(Queue* pq);
void Print(Queue* pq);