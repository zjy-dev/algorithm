#include"LeetCode.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int l = 0, r = nums.size() - 1, mid;
        if(nums[r] == r)
            return r + 1;
        while(l < r)
            if(nums[mid = l + r >> 1] == mid)
                l = mid + 1;
            else
                r = mid;
        
        return l;
    }
};