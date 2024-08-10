#include "Queue.h"

void QueueInit(Queue* pq)
{
    assert(pq);

    pq->_head = NULL;
    pq->_tail = NULL;
}

void QueueDestroy(Queue* pq)
{
    assert(pq);

    QueueNode* cur = pq->_head;
    QueueNode* next = NULL;
    while (cur)
    {
        next = cur->_next;
        free(cur);
        cur = next;
    }

    pq->_head = NULL;
    pq->_tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);

    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {}

    newNode->_data = x;
    newNode->_next = NULL;

    if (pq->_head == NULL)
        pq->_head = newNode;
    else 
        pq->_tail->_next = newNode;

    pq->_tail = newNode;
}

void QueuePop(Queue* pq)
{
    assert(pq && pq->_head);

    QueueNode* next = pq->_head->_next;
    free(pq->_head);
    pq->_head = next;

    if (pq->_head == NULL)
        pq->_tail = NULL;
}

QDataType QueueFront(Queue* pq)
{
    assert(pq && pq->_head);
    
    return pq->_head->_data;
}

QDataType QueueBack(Queue* pq)
{
    assert(pq && pq->_head);

    return pq->_tail->_data;
}

int QueueEmpty(Queue* pq)
{
    assert(pq);

    return pq->_head == NULL ? 1 : 0;
}

size_t QueueSize(Queue* pq)
{
    assert(pq);

    size_t size = 0;
    QueueNode* cur = pq->_head;

    while (cur)
    {
        ++size;
        cur = cur->_next;
    }

    return size;
}

void Print(Queue* pq)
{
    QueueNode* cur = pq->_head;
    
    while (cur)
    {
        printf("%d ", cur->_data);
        cur = cur->_next;
    }

    printf("\n");
}
