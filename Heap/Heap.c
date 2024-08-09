#include "Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
    HPDataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void AdjustDown(HPDataType* a, int n, int root)
{
    int parent = root;
    int child = 2 * parent + 1;

    while (child < n)
    {
        if (child + 1 < n && a[child + 1] < a[child])
            ++child;

        if (a[child] < a[parent])
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

void AdjustUp(HPDataType* a, int child)
{
    int parent = (child - 1) / 2;

    // 若while (parent >= 0)，
    // parent=(child-1)/2;若child为0，则-1/2=0，parent恒大于0
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

void HeapInit(Heap* ph, HPDataType* a, int n)
{
    assert(ph && a);

    ph->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
    if (ph->_a == NULL) {}
    
    memcpy(ph->_a, a, sizeof(HPDataType) * n);
    ph->_size = n;
    ph->_capacity = n;

    // 建堆
	// 从最后开始，保证左右子树都是小堆
    for (int i = (n - 1 - 1) / 2; i >= 0; --i)
        AdjustDown(ph->_a, ph->_size, i);
}

void HeapDestory(Heap* ph)
{
    assert(ph);

    free(ph->_a);
    ph->_a = NULL;
    ph->_size = 0;
    ph->_capacity = 0;
}

void HeapPush(Heap* ph, HPDataType x)
{
    assert(ph);

    if (ph->_size == ph->_capacity)
    {
        ph->_capacity *= 2;
        HPDataType* tmp = (HPDataType*)realloc(ph->_a, sizeof(HPDataType) * ph->_capacity);
        if (tmp == NULL) {}

        ph->_a = tmp;
    }

    ph->_a[ph->_size] = x;
    ++ph->_size;
    AdjustUp(ph->_a, ph->_size - 1);
}

void HeapPop(Heap* ph)
{
    assert(ph && ph->_size > 0);

    Swap(&ph->_a[0], &ph->_a[ph->_size - 1]);
    --ph->_size;
    AdjustDown(ph->_a, ph->_size, 0);
}

HPDataType HeapTop(Heap* ph)
{
    assert(ph && ph->_size > 0);

    return ph->_a[0];
}

// 降序
void HeapSort(int* a, int n)
{
    // 建堆
    for (int i = (n - 1 - 1) / 2; i >= 0; --i)
        AdjustDown(a, n, i);

    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        --end;
    }
}

void Print(Heap* ph)
{
    for (int i = 0; i < ph->_size; ++i)
        printf("%d ", ph->_a[i]);

    printf("\n");
}