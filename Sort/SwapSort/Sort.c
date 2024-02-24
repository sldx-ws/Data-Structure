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

int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else // a[left] >= a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

// [left, right] -- O(N)
// hoare
int PartSort(int* a, int left, int right)
{
    assert(a);

	// 三数取中
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int keyi = left;  // 取左边做key，先让right走
	while (left < right)
	{
		// right找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// left找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		if (left < right)
			Swap(&a[left], &a[right]);
	}

	int meeti = left;

	Swap(&a[meeti], &a[keyi]);

	return meeti;
}

// [left, right] 闭区间
// O(N*logN)~O(N^2)
// 使用三数取中O(N*logN)
void QuickSort(int* a, int left, int right)
{
    assert(a);

    if (left < right)
    {
        int keyi = PartSort(a, left, right);
        //[left, keyi-1] keyi [keyi+1, right]
        QuickSort(a, left, keyi - 1);
        QuickSort(a, keyi + 1, right);
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
