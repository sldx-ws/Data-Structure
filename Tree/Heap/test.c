#include "Heap.h"

void test()
{
    printf("建堆：");
    HPDataType a[] = {3, 5, 6, 7, 2, 9};
    Heap hp;
    HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
    Print(&hp);

    printf("0 4 入堆：");
    HeapPush(&hp, 0);
    HeapPush(&hp, 4);
    Print(&hp);
    
    printf("堆顶元素出堆：");
    HeapPop(&hp);
    Print(&hp);

    printf("堆顶元素：%d\n", HeapTop(&hp));

    HeapDestory(&hp);
}

void test_sort()
{
    HPDataType a[] = {3, 5, 6, 7, 2, 9};
    int size = sizeof(a) / sizeof(a[0]);
    HeapSort(a, size);

    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int main()
{
    // test();
    testHeapSort();

    return 0;
}
