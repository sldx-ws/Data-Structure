#include "Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
    assert(p1 && p2);

    HPDataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// 向下调整算法（默认建小堆） O(logN)
// 前提：左右子树都是小堆
void AdjustDown(HPDataType* a, int n, int root)
{
    assert(a);

    int parent = root;
    int child = 2 * parent + 1;

    while (child < n)
    {
        if (child + 1 < n && a[child + 1] < a[child])  // 大堆改
        {
            ++child;
        }

        if (a[child] < a[parent])  // 大堆改
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = 2 * parent + 1;
        }
        else 
        {
            break;
        }
    }
}

// 向上调整算法
void AdjustUp(HPDataType* a, int child)
{
    assert(a);

    int parent = (child - 1) / 2;

    // 若while (parent >= 0)，55行parent恒大于0
    while (child > 0)
    {
        if (a[child] < a[parent])
        {
            Swap(&a[child], &a[parent]);
            child = parent;
            parent = (child - 1) / 2; 
        }
        else 
        {
            break;
        }
    }
}

// init destory
void HeapInit(Heap* php, HPDataType* a, int n)
{
    assert(php && a);

    php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
    if (php->_a == NULL)
    {
        printf("内存申请失败\n");
        exit(-1);
    }
    
    memcpy(php->_a, a, sizeof(HPDataType) * n);
    php->_size = n;
    php->_capacity = n;

    // 建堆
	// 从最后开始，保证左右子树都是小堆
    for (int i = (n - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDown(php->_a, php->_size, i);
    }
}

void HeapDestory(Heap* php)
{
    assert(php);

    free(php->_a);
    php->_a = NULL;
    php->_size = 0;
    php->_capacity = 0;
}

// push pop
void HeapPush(Heap* php, HPDataType x)
{
    assert(php);

    if (php->_size == php->_capacity)
    {
        php->_capacity *= 2;
        HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * php->_capacity);
        if (tmp == NULL)
        {
            printf("内存申请失败\n");
            exit(-1);
        }

        php->_a = tmp;
    }

    php->_a[php->_size] = x;
    ++php->_size;
    AdjustUp(php->_a, php->_size - 1);
}

void HeapPop(Heap* php)
{
    assert(php);
    assert(php->_size > 0);

    Swap(&php->_a[0], &php->_a[php->_size - 1]);
    --php->_size;
    AdjustDown(php->_a, php->_size, 0);
}

// Top
HPDataType HeapTop(Heap* php)
{
    assert(php);
    assert(php->_size > 0);

    return php->_a[0];
}

void Print(Heap* php)
{
    assert(php);

    for (int i = 0; i < php->_size; ++i)
    {
        printf("%d ", php->_a[i]);
    }

    printf("\n");
}

// heap sort
void HeapSort(int* a, int n)
{
    assert(a);

    // 默认降序
    // 升序建大堆，降序建小堆
    // 假设树有N个节点，树高度：logN
	// 要注意这里建堆的时间复杂度不是O(N * logN)，是O(N)
	// 因为每次不是从0开始往下调
    for (int i = (n - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDown(a, n, i);
    }

    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        --end;
    }
}
