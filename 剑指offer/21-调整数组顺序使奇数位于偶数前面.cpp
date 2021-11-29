#include"LeetCode.h"

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j)
        {
            while(i < j and nums[i] & 1)
                i++;
            while(i < j and !(nums[j] & 1))
                j--;
            
            swap(nums[i], nums[j]);
        }

        return nums;
    }
};