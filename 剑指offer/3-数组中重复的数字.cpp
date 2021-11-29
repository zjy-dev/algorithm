#include"LeetCode.h"

class Solution{
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++)
            while(nums[i] != i)
            {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[nums[i]], nums[i]);
            }
        
        return 0;
    }
};