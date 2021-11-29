#include"LeetCode.h"

class Solution{
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans = 0;
        for(int i = 31; i >= 0; i--)
        {
            int cnt = 0;
            for(const auto& num : nums)
                cnt += (num >> i) & 1;
            ans = (ans << 1) + (cnt % 3);
        }

        return ans;
    }
};