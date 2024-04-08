void quickSort(vector<int>& v, int low, int high) {
    if (low < high) {
        int i = low;
        int j = high;
        int pivot = v[low + (high - low) / 2]; 

        while (i <= j) {
            while (v[i] < pivot)
                ++i;

            while (v[j] > pivot) 
                --j;

            if (i <= j) {
                swap(v[i], v[j]);
                ++i;
                --j;
            }
        }

        quickSort(v, low, j);
        quickSort(v, i, high);
    }
}