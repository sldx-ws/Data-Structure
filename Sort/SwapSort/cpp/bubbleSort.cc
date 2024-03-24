void bubbleSort(vector<int> &v) 
{
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        bool flag = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }

        if (!flag)
            break;
    }
}