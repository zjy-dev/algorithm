#include"LeetCode.h"

class Solution {
public:
    vector<int> constructArr(vector<int>& nums) 
    {
        auto n = nums.size();
        if(!n)
            return {};
        vector<int> ans(n, 1);
        for(int i = 1; i < n; i++)
            ans[i] = nums[i - 1] * ans[i - 1];
        int tmp = 1;
        for(int i = n - 2; i >= 0; i--)
            tmp *= nums[i + 1], ans[i] *= tmp;
        
        return ans;
    }
};