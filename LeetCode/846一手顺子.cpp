#include"LeetCode.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int len) 
    {
        int n = nums.size();
        unordered_map<int, int> hash;

        for(const auto& val : nums)
            hash[val]++;
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++)
        {
            if(!hash[nums[i]])
                continue;

            for(int j = 0; j < len; j++)
                if(!hash[nums[i] + j])
                    return false;
                else
                    hash[nums[i] + j]--;
        }

        return true;
    }
};    