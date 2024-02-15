#include "SeqList.h"

// 初始化 销毁
void SeqListInit(SeqList* psl)
{
    // 方法一
    //psl->_a = NULL;
    //psl->_size = 0;
    //psl->_capacity = 0;
    
    // 方法二
    psl->_a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
    if (psl->_a == NULL)
    {
        printf("申请内存失败\n");
        exit(-1);
    }

    psl->_size = 0; 
    psl->_capacity = 4;
}

void SeqListDestory(SeqList* psl)
{
    assert(psl->_a);

    free(psl->_a);
    psl->_a = NULL;
    psl->_size = 0;
    psl->_capacity = 0;
}

// 检查容量
void SeqListCheckCapacity(SeqList* psl)
{
    // 如果满了，则增容
    if (psl->_size >= psl->_capacity)
    {
        psl->_capacity *= 2;
        psl->_a = (SLDataType*)realloc(psl->_a, sizeof(SLDataType) * psl->_capacity);
        if (psl->_a == NULL)
        {
            printf("扩容失败\n");
            exit(-1);
        }
    }
}

// 尾插尾删 头插头删
void SeqListPushBack(SeqList* psl, SLDataType x)
{
    assert(psl);

    SeqListCheckCapacity(psl);

    psl->_a[psl->_size] = x;
    ++psl->_size;
}

void SeqListPopBack(SeqList* psl)
{
    assert(psl);
    assert(psl->_size);

    --psl->_size;
}

void SeqListPushFront(SeqList* psl, SLDataType x)
{
    assert(psl);

    SeqListCheckCapacity(psl);

    int end = psl->_size - 1;
    while(end >= 0)
    {
        psl->_a[end + 1] = psl->_a[end];
        --end;
    }

    psl->_a[0] = x;
    ++psl->_size;
}

void SeqListPopFront(SeqList* psl)
{
    assert(psl);
    assert(psl->_size);

    int begin = 0;
    while(begin < psl->_size - 1)
    {
        psl->_a[begin] = psl->_a[begin + 1];
        ++begin;
    }

    --psl->_size;
}

// 任意位置插入删除
void SeqListInsert(SeqList* psl, int pos, SLDataType x)
{
    assert(psl);
    // 若形参pos的类型为size_t，则不用判断 >= 0
    assert(pos >= 0 && pos <= psl->_size);

    ++psl->_size;
    SeqListCheckCapacity(psl);

    int end = psl->_size - 1;
    while (end > pos)
    {
        psl->_a[end] = psl->_a[end - 1];
        --end;
    }

    psl->_a[pos] = x;
}

void SeqListErase(SeqList* psl, int pos)
{
    assert(psl);
    assert(pos >= 0 && pos < psl->_size);

    int begin = pos;
    while (begin < psl->_size - 1)
    {
        psl->_a[begin] = psl->_a[begin + 1];
        ++begin;
    }

    --psl->_size;
}

// print 
void Print(SeqList* psl)
{
    assert(psl);

    for (int i = 0; i < psl->_size; ++i)
    {
        printf("%d ", psl->_a[i]);
    }

    printf("\n");
}

// 查找（返回下标）
int SeqListFind(SeqList* psl, SLDataType x)
{
    assert(psl);

    for (int i = 0; i < psl->_size; ++i)
    {
        if (x == psl->_a[i])
        {
            return i;
        }
    }

    return -1;
}
