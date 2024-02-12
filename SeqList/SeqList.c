#include "SeqList.h"

// 初始化
void SeqListInit(SL* ps)
{
    // 方法一
    //ps->_a = NULL;
    //ps->_size = 0;
    //ps->_capacity = 0;
    
    // 方法二
    ps->_a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
    if (ps->_a == NULL)
    {
        printf("申请内存失败\n");
        exit(-1);
    }

    ps->_size = 0; 
    ps->_capacity = 4;
}

// 检查容量
void SeqListCheckCapacity(SL* ps)
{
    // 如果满了，则增容
    if (ps->_size >= ps->_capacity)
    {
        ps->_capacity *= 2;
        ps->_a = (SLDataType*)realloc(ps->_a, sizeof(SLDataType) * ps->_capacity);
        if (ps->_a == NULL)
        {
            printf("扩容失败\n");
            exit(-1);
        }
    }
}

// 尾插尾删 头插头删
void SeqListPushBack(SL* ps, SLDataType x)
{
    assert(ps);

    SeqListCheckCapacity(ps);

    ps->_a[ps->_size] = x;
    ++ps->_size;
}

void SeqListPopBack(SL* ps)
{
    assert(ps);
    assert(ps->_size);

    --ps->_size;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
    assert(ps);

    SeqListCheckCapacity(ps);

    int end = ps->_size - 1;
    while(end >= 0)
    {
        ps->_a[end + 1] = ps->_a[end];
        --end;
    }

    ps->_a[0] = x;
    ++ps->_size;
}

void SeqListPopFront(SL* ps)
{
    assert(ps);
    assert(ps->_size);

    int start = 0;
    while(start < ps->_size - 1)
    {
        ps->_a[start] = ps->_a[start + 1];
        ++start;
    }

    --ps->_size;
}

// 任意位置插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

// print 
void Print(SL* ps)
{
    assert(ps);

    for (int i = 0; i < ps->_size; ++i)
    {
        printf("%d ", ps->_a[i]);
    }

    printf("\n");
}

// 查找
int SeqListFind(SL* ps, SLDataType x);
