#pragma once 

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDataType;

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

// init destory
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

// push pop
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

// front back
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

// empty size
int QueueEmpty(Queue* pq);
size_t QueueSize(Queue* pq);

void Print(Queue* pq);
