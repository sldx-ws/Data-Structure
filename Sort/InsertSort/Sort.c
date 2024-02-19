#include "Sort.h"

void InsertSort(int* a, int n)
{
    assert(a);
    
    for (int i = 0; i < n - 1; ++i)
    {
        int endIndex = i;
        int tmp = a[endIndex + 1];
        while(endIndex >=0)
        {
            if (tmp < a[endIndex])
            {
                a[endIndex + 1] = a[endIndex];
                --endIndex;
            }
            else 
            {
                break;
            }
            
            a[endIndex + 1] = tmp;
        }
    }
}
void ShellSort(int* a, int n);

void Print(int* a, int n)
{
    assert(a);

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}
