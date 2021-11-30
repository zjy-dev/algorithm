#include"LeetCode.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ans = 0;
        int n = nums.size();

        unordered_set<int> hash;
        for(int i = 0; i < n; i++)
            hash.insert(nums[i]);
        
        for(auto val : hash)
        {
            if(hash.count(val - 1))
                continue;
            int t = 0;
            while(hash.count(val + 1))
                t++, val++;
            ans = max(ans, t);
        }

        return ans;
    }   
};