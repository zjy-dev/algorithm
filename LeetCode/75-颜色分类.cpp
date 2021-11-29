#include"LeetCode.h"

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0, j = n - 1, t = 0; t <= j; t++)
        {
            while(t <= j and nums[t] == 2)
                swap(nums[t], nums[j--]);
            if(nums[t] == 0)
                swap(nums[t], nums[i++]);
        }
    }
};