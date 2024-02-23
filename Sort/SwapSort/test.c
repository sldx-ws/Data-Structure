#include "Sort.h"

void test01()
{
    int a[] = { 7, 6, 9, 1, 0, 4, 3, 2, 8 };
    int size = sizeof(a) / sizeof(a[0]);
    BubbleSort(a, size);
    Print(a, size);
}

int main()
{
    test01();

    return 0;
}
