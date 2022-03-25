#include"LeetCode.h"


/**
 * 时间复杂度 -> O(logn), 快速幂
 * 空间复杂度 -> O(1)
 */
typedef long long LL;
const int mod = 1e+9 + 7;

class Solution {
public:
    int cuttingRope(int n) {
        // 如果n % 3 != 1, 则分尽可能多的3
        int cnt3 = n / 3;

        // 如果n % 3 == 1, 则把最后一个3和1加在一起变成4, 因为3 * 1 < 4
        if (n % 3 == 1) {
            cnt3--;
        }

        int ans = quick_mi(3, cnt3, mod);
        int t = n - cnt3 * 3;
        // t可能的取值有0, 2, 4
        if (t != 0) {
            ans = (LL)ans * t % mod;
        }
        return ans;
    }

    // logn的时间复杂度求出(m ^ n) % mod 
    int quick_mi(int m, int n, int mod) {
        int ans = 1, t = m;
        while (n) {
            if (n & 1 == 1) {
                ans = (LL)ans * t % mod;
            }
            t = (LL)t * t % mod;
            n >>= 1;
        }

        return ans;
    }
};