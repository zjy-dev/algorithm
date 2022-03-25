#include"LeetCode.h"

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) 
    {
        // 假设a和b就是那两个只出现一次的数
        // 那么我们可以轻松得到a ^ b
        int a_xor_b = 0;
        for (const auto& val : nums) {
            a_xor_b ^= val;
        }
        
        // 从后往前寻找a和b不同的一个二进制位
        // 而a_xor_b的二进制位中, 为1则说明a和b的该位不同
        int flag = 1;
        while ((flag & a_xor_b) == 0) {
            flag <<= 1;
        }

        // 以该位为依据, 将数据分为两组, 1组和0组
        // 1组全部异或一下, 0组内部全部异或一下, 即可得到答案
        // 至于谁是1谁是0无须在意
        int a = 0, b = 0;
        for (const auto& val : nums) {
            if ((val & flag) == 0) {
                a ^= val;
            } else {
                b ^= val;
            }
        }
        
        return {a, b};
    }
};