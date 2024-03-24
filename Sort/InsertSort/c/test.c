#include "Sort.h"

void test01()
{
    int arr[] = { 3, 5, 2, 7, 3, 4, 0 };
    InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
    Print(arr, sizeof(arr) / sizeof(arr[0]));
}

void test02()
{
    int arr[] = { 3, 5, 2, 7, 3, 4, 0 };
    ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
    Print(arr, sizeof(arr) / sizeof(arr[0]));
}

int main()
{
    //test01(); 
    test02();

    return 0;
}
