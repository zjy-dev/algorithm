#include "LeetCode.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        // 为了维护最大值, 我们维护一个严格单减的单调队列
        // 当然了, 存下标不存具体的数, 这样滑动起来判断越界会非常的方便
        // 而且存下标从各种方面都优于存数

        // 而为什么要严格单减呢? 
        // 因为对于窗口中的i和j, 有 i < j 且 nums[i] <= nums[j]
        // 那么我们在获取最大值的时候, 永远是nums[j]在发挥作用, i没有存在的意义
        // 所以我们要不断尾删nums[i], 这样一来j前面所有数都比他大, 也就单减了
        deque<int> q;

        // 预处理前k和数
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            // 删除所有小于等于nums[i]的数
            while (q.empty() == false && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        for (int i = k; i < n; i++) {
            // 删除所有小于等于nums[i]的数
            while (q.empty() == false && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }

            q.push_back(i);

            // 滑动窗口要删除滑出窗口外的元素, 也就是小于等于i - k的元素
            while (q.empty() == false && q.front() <= i - k) {
                q.pop_front();
            }

            // 更新答案
            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};