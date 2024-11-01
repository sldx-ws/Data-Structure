#include <stdio.h>
#include <assert.h>

// 前提数组有序
// 假设数组升序
// O(logN)
int BinarySearch(int* a, int n, int key) 
{
    assert(a);

    int left = 0;
    int right = n - 1;

    while (left <= right) 
    {
        //int mid = (left + right) / 2;  // 有整型溢出风险
        int mid = left + (right - left) / 2;

        if (a[mid] < key)
            left = mid + 1;
        else if (a[mid] > key)
            right = mid - 1;
        else 
            return mid; 
    }

    return -1;
}
