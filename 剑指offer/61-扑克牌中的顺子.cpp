#include"LeetCode.h"

class Solution {
public:
    bool isStraight(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int flag = 0;
        for(int i = 0; i < 4; i++)
            if(!nums[i])
                flag = i + 1;
            else if(nums[i] == nums[i + 1])
                return false;
        
        return nums[4] - nums[flag] < 5;
    }
};