#include "BinarySearch.h"

void test()
{
    int arr[] = { 0, 1, 2, 3, 4, 5 };
    int index = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 3);
    printf("%d\n", index);
}

int main()
{
    test();

    return 0;
}
