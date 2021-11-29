#include"LeetCode.h"

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size(), farthest = 0;
        for(int i = 0; i < n; i++)
        {
            if(i <= farthest)   
                farthest = max(farthest, i + nums[i]);
            if(farthest >= n - 1)
                return true;
        }

        return false;
    }
};