void adjustDown(vector<int>& v, int dest, int parent)
{
    int child = 2 * parent + 1;
    while (child < dest){
        if (child + 1 < dest && v[child + 1] > v[child])
            ++child;

        if (v[child] > v[parent]){
            swap(v[child], v[parent]);
            parent = child;
            child = 2 * parent + 1;
        } else {
            break;
        }
    }
}

void heapSort(vector<int>& v)
{
    int n = v.size();
    // 建堆
    for (int i = (n - 1 - 1) / 2; i >= 0; --i)
        adjustDown(v, n, i);

    // 排序
    for (int i = 1; i < n; ++i){
        swap(v[0], v[n - i]);
        adjustDown(v, n - i, 0);
    }
}