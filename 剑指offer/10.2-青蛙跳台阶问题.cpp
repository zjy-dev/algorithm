#include"LeetCode.h"

class Solution {
public:
    const int mod = 1e+9 + 7;
    int numWays(int n) {
        if(n < 2)
            return 1;
        n--;
        int a = 1, b = 1;
        while(n--)
        {
            auto t = a;
            a = b;
            b = (b + t) % mod;
        }

        return b;
    }
};