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

void AdjustDown(int* a, int n, int parent)
{
    assert(a);

	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		// 找出小的那个孩子
		if (minChild + 1 < n && a[minChild + 1] > a[minChild])
		{
			minChild++;
		}

		if (a[minChild] > a[parent])
		{
			Swap(&a[minChild], &a[parent]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// O(N*logN)
void HeapSort(int* a, int n)
{
    assert(a);

	// 升序 -- 大堆
	// 降序 -- 小堆
	// 建堆 -- 向下调整建堆 - O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// 选数 N*logN
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
		++i;
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
