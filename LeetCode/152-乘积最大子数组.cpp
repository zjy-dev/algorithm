#include"LeetCode.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        auto ans = nums[0], dpMin = ans, dpMax = ans;

        for(int i = 1; i < n; i++)
        {
            int mx = dpMax, mn = dpMin; 
            dpMin = min(nums[i], min(nums[i] * mn, nums[i] * mx));
            dpMax = max(nums[i], max(nums[i] * mx, nums[i] * mn));
            ans = max(ans, dpMax);
        }
        
        return ans;
    }
};