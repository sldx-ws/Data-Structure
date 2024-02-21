#include "Sort.h"

// 最坏时间复杂度O(N^2) -- 逆序
// 最好时间复杂度O(N) -- 顺序有序
void InsertSort(int* a, int n)
{
    assert(a);
    
    for (int i = 0; i < n - 1; ++i)
    {
        int endi = i;
        int tmp = a[endi + 1];
        while(endi >=0)
        {
            if (a[endi] > tmp)
            {
                a[endi + 1] = a[endi];
                --endi;
            }
            else 
            {
                break;
            }
            
            a[endi + 1] = tmp;
        }
    }
}

// O(N^1.3)
void ShellSort(int* a, int n)
{
    assert(a);

	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		// [0,endi] 插入 endi+gap [0, endi+gap]有序  -- 间隔为gap的数据
		for (int i = 0; i < n - gap; ++i)
		{
			int endi = i;
			int tmp = a[endi + gap];

			while (endi >= 0)
			{
				if (a[endi] > tmp)
				{
					a[endi + gap] = a[endi];
					endi -= gap;
				}
				else
				{
					break;
				}
			}

			a[endi + gap] = tmp;
		}
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
