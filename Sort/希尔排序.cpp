#include<bits/stdc++.h>
using namespace std;

void shell_sort(int array[], int length) {
    int h = 1;
    while (h < length / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < length; i++) {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
                std::swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
}

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
    cout << "Ï£¶ûÅÅÐò" << endl;
    for (const auto& val : arr) {
        printf("%d ", val);
    }
    return 0;
}