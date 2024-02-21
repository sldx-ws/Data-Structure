#include "Sort.h"

void test01()
{
    int a[] = {3, 6, 1, 0, 4, 2, 8, 9, 5};
    int size = sizeof(a) / sizeof(a[0]);

    SelectSort(a, size);
    Print(a, size);
}

int main()
{
    test01();

    return 0;
}
