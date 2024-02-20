#include "Sort.h"

// 最坏时间复杂度O(N^2) -- 逆序
// 最好时间复杂度O(N) -- 顺序有序
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

// O(N^1.3)
void ShellSort(int* a, int n)
{
    assert(a);

	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		// [0,endIndex] 插入 endIndex+gap [0, endIndex+gap]有序  -- 间隔为gap的数据
		for (int i = 0; i < n - gap; ++i)
		{
			int endIndex = i;
			int tmp = a[endIndex + gap];

			while (endIndex >= 0)
			{
				if (a[endIndex] > tmp)
				{
					a[endIndex + gap] = a[endIndex];
					endIndex -= gap;
				}
				else
				{
					break;
				}
			}

			a[endIndex + gap] = tmp;
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
