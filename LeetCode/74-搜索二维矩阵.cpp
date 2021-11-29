#include"LeetCode.h"

class Solution {
public:
    int row, col;
    int getVal(vector<vector<int>>& nums, int idx)
    {
        return nums[idx / col][idx % col];
    }

    bool searchMatrix(vector<vector<int>>& nums, int tar) 
    {
        row = nums.size(), col = nums[0].size();
        int l = 0, r = row * col - 1, mid;
        while(l < r)
            if(getVal(nums, mid = (l + r + 1) >> 1) > tar)
                r = mid - 1;
            else
                l = mid;
        return getVal(nums, l) == tar;
    }
};