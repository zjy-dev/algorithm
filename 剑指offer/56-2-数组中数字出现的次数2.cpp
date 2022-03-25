#include"LeetCode.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        // 枚举每一位
        for (int i = 31; i >= 0; i--) {
            int cnt = 0;
            int flag = (1 << i);

            // 统计该位中1的个数, 存入cnt
            for (const auto& val : nums) {
                if ((val & flag) != 0) {
                    cnt++;
                }
            }

            // cnt % 3就是答案的该位, 因为其他数字在该位1的数量只能出现3次或0次
            ans = (ans << 1) + (cnt % 3);
        }

        return ans;
    }
};