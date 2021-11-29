#include"LeetCode.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for(int i = 0; i < n; i++)
        {
            if(hash.count(target - nums[i]))
                return {hash[target - nums[i]], i};
            hash[nums[i]] = i;
        }

        return {};
    }
};