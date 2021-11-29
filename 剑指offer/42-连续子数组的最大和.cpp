#include"LeetCode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size(), ans = nums[0], pre = nums[0];
        for(int i = 1; i < n; i++)
        {
            pre = max(nums[i], pre + nums[i]);
            ans = max(pre, ans);
        }

        return ans;
    }
};