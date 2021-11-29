#include"LeetCode.h"

class Solution {
public:
    void rotate(vector<vector<int>>& nums) 
    {
        int n = nums.size();
        //水平翻转
        for(int i = 0; i < (n >> 1); i++)
            for(int j = 0; j < n; j++)
                swap(nums[i][j], nums[n - i - 1][j]);
        
        //主对角线翻转(左上--右下)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                swap(nums[i][j], nums[j][i]);
    }
};