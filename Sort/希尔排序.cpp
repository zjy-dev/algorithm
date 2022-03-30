#include<bits/stdc++.h>
using namespace std;

void shell_sort(vector<int> &arr) {
    int n = arr.size();
    
    for (int gap = (n >> 1); gap > 0; gap >>= 1) {
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
                swap(arr[j], arr[j + gap]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 1, 5, 8, 0, 5, 2, 6};
    shell_sort(arr);
    cout << "希尔排序:" << endl;
    for (const auto& val : arr) {
        printf("%d ", val);
    }
    return 0;
}