#include "Sort.h"

void test01()
{
    int a[] = { 7, 6, 9, 1, 0, 4, 3, 2, 8 };
    int size = sizeof(a) / sizeof(a[0]);
    BubbleSort(a, size);
    Print(a, size);
}

void test02()
{
    int a[] = { 7, 6, 9, 1, 0, 4, 3, 2, 8 };
    int size = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, size - 1);
    Print(a, size);
}

int main()
{
    //test01();
    test02();

    return 0;
}
