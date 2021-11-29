#include"LeetCode.h"

class Solution {
public:
    bool verifyPostorder(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    bool dfs(vector<int>& nums, int i, int j)
    {
        if(i >= j)
            return true;
        int root = nums[j];
        int p = i;
        while(nums[p] < root)
            p++;
        auto t = p;
        while(nums[p] > root)
            p++;
        return p == j and dfs(nums, i, p - 1) and dfs(nums, p, j - 1);
    }
};