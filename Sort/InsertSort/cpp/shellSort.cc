void shellSort(vector<int>& v)
{
    int n = v.size();

    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1;

        for (int i = gap; i < n; ++i)
        {
            int tmp = v[i];
            int j = i;

            while (j >= gap && v[j - gap] > tmp)
            {
                v[j] = v[j - gap];
                j -= gap;
            }

            v[j] = tmp;
        }
    }
}