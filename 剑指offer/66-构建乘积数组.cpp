#include"LeetCode.h"

class Solution {
public:
    vector<int> constructArr(vector<int>& arr) {
        int n = arr.size();

        if (n == 0) {
            return {};
        }

        vector<int> ans(n, 1);

        // 先计算[0, k - 1]
        for (int i = 1; i < n; i++) {
            ans[i] = arr[i - 1] * ans[i - 1];
        }

        // 再计算[k, n - 1]
        int temp = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= temp;
            temp *= arr[i]; 
        }

        return ans;
    }
};