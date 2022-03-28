#include"LeetCode.h"

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;

        // dp + 滚动数组优化
        while (n-- > 1) {
            int t = b;
            b += a;
            a = t;
        }

        return b;
    }
};