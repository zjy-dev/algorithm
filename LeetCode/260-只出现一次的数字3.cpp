#include"LeetCode.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int a_xor_b = 0;
        for(const auto& val : nums)
            a_xor_b ^= val;
        
        int flag = (a_xor_b == INT_MIN) ? INT_MIN : a_xor_b & (-a_xor_b);
        int a = 0, b = 0;
        for(const auto& val : nums)
            if(val & flag)
                a ^= val;
            else
                b ^= val;
        
        return {a, b};
    }
};