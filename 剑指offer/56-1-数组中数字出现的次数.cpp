#include"LeetCode.h"

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) 
    {
        int a_xor_b = 0;
        for(const auto& num : nums)
            a_xor_b ^= num;
        
        int flag = a_xor_b == INT_MIN ? INT_MIN : a_xor_b & (-a_xor_b);
        int a = 0, b = 0;
        for(const auto& num : nums)
            if(num & flag)
                a ^= num;
            else
                b ^= num;
        
        return {a, b};
    }
};