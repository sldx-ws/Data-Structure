#include "Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 最坏情况：O(N^2)
// 最好情况：O(N)
void BubbleSort(int* a, int n)
{
    assert(a);

	for (int i = 0; i < n; ++i)
	{
		int flag = 0;
		for (int j = 1; j < n - i; ++j)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
}

void Print(int* a, int n)
{
    assert(a);

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}
