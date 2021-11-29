#include"LeetCode.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) 
    {
        for(int i = 0, j = nums.size() - 1; ; )
            if(nums[i] + nums[j] > tar)
                j--;
            else if(nums[i] + nums[j] < tar)
                i++;
            else
                return {nums[i], nums[j]};
        
        return {};
    }
};