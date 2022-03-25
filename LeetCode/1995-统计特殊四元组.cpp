#include"LeetCode.h"

class Solution {
public:
    int countQuadruplets(vector<int>& nums) 
    {
        int ans = 0, n = nums.size();
        unordered_map<int, int> hash;
        //a + b == d - c
        for(int b = n - 3; b >= 1; b--)
        {
            int c = b + 1;
            for(int d = b + 2; d < n; d++)
                hash[nums[d] - nums[c]]++;
            
            for(int a = 0; a < b; a++)
                ans += hash[nums[a] + nums[b]];
        }

        return ans;
    }
};