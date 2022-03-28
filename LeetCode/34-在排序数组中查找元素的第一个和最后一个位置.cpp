#include "LeetCode.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int n = nums.size();

        if (n == 0) {
            return {-1, -1};
        }

        vector<int> ans(2);
        
        // 从左往右寻找第一个大于等于tar的数
        int l = 0, r = n - 1, mid;
        while (l < r) {
            if (nums[mid = (l + r) >> 1] >= tar) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (nums[l] != tar) {
            return {-1, -1};
        }

        ans[0] = l;

        // 从右往左寻找第一个小于等于tar的数
        l = 0, r = n - 1;
        while (l < r) {
            if (nums[mid = (l + r + 1) >> 1] <= tar) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        ans[1] = l;

        return ans;
    }
};