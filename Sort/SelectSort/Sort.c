#include "Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 最坏时间复杂度：O(N^2)
// 最好时间复杂度：O(N^2)
void SelectSort(int* a, int n)
{
    assert(a);

	int begini = 0;
    int endi = n - 1;

	while (begini < endi)
	{
		// 选出最小的放begini位置
		// 选出最大的放endi位置
		int mini = begini, maxi = begini;
		for (int i = begini + 1; i <= endi; ++i)
		{
			if (a[i] > a[maxi])
				maxi = i;

			if (a[i] < a[mini])
				mini = i;
		}

		Swap(&a[begini], &a[mini]);

		// 修正一下maxi
		if (maxi == begini)
			maxi = mini;

		Swap(&a[endi], &a[maxi]);
		++begini;
		--endi;
	}
}

void Print(int* a, int size)
{
    assert(a);

    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}
