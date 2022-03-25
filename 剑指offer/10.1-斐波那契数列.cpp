#include"LeetCode.h"

/**
 * 时间复杂度 -> O(n), dp
 * 空间复杂度 -> O(1), 滚动数组优化, 二维降一维
 */
const int mod = 1e+9 + 7;

class Solution {
public:
    int fib(int n) {
        // 特判0和1, 此时不需要dp
        if (n < 2) {
            return n;
        }

        // dp + 滚动数组, 循环n - 1次返回b(可以以n = 2为例, 循环1次返回b即可)
        int a = 0, b = 1;
        while (n > 1) {
            int t = b;
            b = (a + b) % mod;
            a = t;

            n--;
        }

        return b;
    }
};
