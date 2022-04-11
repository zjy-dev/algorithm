#include "LeetCode.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // 0要特判一下
        if (n == 0) {
            return 1;
        }

        // 对于k位数, 要满足题干, 则
        // 第一位[1..9], 第二位[0...9]且不等于第一位...
        // 也就是说, 方案数为: 9 * A(9, k - 1)

        // 那我们只要把1位数, 2位数, 3位数...n位数的情况加起来即可

        // ans初始为一位数的情况, cur初始为9代表第一位填[1..9]
        int ans = 10, cur = 9;

        // 枚举每一位
        for (int i = 2; i <= n; i++) {
            cur *= (9 - i + 2);
            ans += cur;
        }

        return ans;
    }
};