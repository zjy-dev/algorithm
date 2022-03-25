#include"LeetCode.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        // 哈希表, 秒杀
        int n = nums.size();
        unordered_map<int, int> hash;
        
        for (int i = 0; i < n; i++) {
            if (hash.count(tar - nums[i]) == 1) {
                return {i, hash[tar - nums[i]]};
            }

            hash[nums[i]] = i;
        }

        return {};
    }
};