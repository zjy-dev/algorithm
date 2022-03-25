#include<bits/stdc++.h>
using namespace std;

void insert_sort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
            swap(arr[j], arr[j + 1]);
        }
    }
}

int main(int argc, char const *argv[]) {
    vector<int> arr = {3, 1, 5, 8, 0, 5, 2, 6};
    insert_sort(arr);
    for (const auto& val : arr) {
        printf("%d ", val);
    }
    return 0;
}