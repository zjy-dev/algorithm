#include<bits/stdc++.h>
using namespace std;

void quick_sort(vector<int> &arr, int l, int r) {
    // 递归边界, 1个元素不用排序
    if (l >= r) {
        return;
    }

    int i = l - 1, j = r + 1, flag = arr[(l + r) >> 1];

    while (i < j) {
        while(arr[++i] < flag);
        while(arr[--j] > flag);
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    } 

    quick_sort(arr, l , j);
    quick_sort(arr, j + 1, r);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 1, 5, 8, 0, 5, 2, 6};
    quick_sort(arr, 0, arr.size() - 1);
    cout << "快速排序" << endl;
    for (const auto& val : arr) {
        printf("%d ", val);
    }
    return 0;
}