#include "Sort.h"

void test01()
{
    int a[] = {3, 6, 1, 0, 4, 2, 8, 9, 5};
    int size = sizeof(a) / sizeof(a[0]);

    SelectSort(a, size);
    Print(a, size);
}

void test02()
{
    int a[] = {3, 6, 1, 0, 4, 2, 8, 9, 5};
    int size = sizeof(a) / sizeof(a[0]);

    HeapSort(a, size);
    Print(a, size);
}

int main()
{
    //test01();
    test02();

    return 0;
}
