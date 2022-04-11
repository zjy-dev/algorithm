#include"LeetCode.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0 || arr.size() == 0) {
            return {};
        }

        // priority_queue默认是大根堆
        priority_queue<int> heap;

        int n = arr.size();

        // 初始化堆, 将前k个元素放入堆
        for (int i = 0; i < k; i++) {
            heap.push(arr[i]);
        }

        for (int i = k; i < n; i++) {
            // 如果arr[i]大于堆中的最大值, 则其一定不是最小的k个数
            // 反之, 堆中的最大值一定不是最小的k个数
            if (arr[i] < heap.top()) {
                heap.pop();
                heap.push(arr[i]);
            }
        }

        vector<int> ans;
        while (heap.empty() == false) {
            ans.push_back(heap.top());
            heap.pop();
        }

        return ans;
    }
};