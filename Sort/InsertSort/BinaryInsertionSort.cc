int binarySearch(const vector<int>& v, int key, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (v[mid] < key)
            low = mid + 1;
        else if (v[mid] > key)
            high = mid - 1;
        else
            return mid;
    }

    return low;
}

void binaryInsertionSort(vector<int>& v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        int key = v[i];
        int j = i - 1;
        int insertIndex = binarySearch(v, key, 0, j);

        while (j >= insertIndex)
        {
            v[j + 1] = v[j];
            --j;
        }

        v[j + 1] = key;
    }
}