#include"LeetCode.h"

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // 如果a的出现次数超过长度的一半, 则排序后, 中间的数一定是a
        return nums[nums.size() >> 1];
    }
};