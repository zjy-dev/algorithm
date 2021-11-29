#include"LeetCode.h"

class Solution {
public:
    double myPow(double x, int n) {
        if(!x)
            return 0;
        long long k = n;
        if(n < 0)
            x = 1 / x, k = -k;
        double res = 1;
        while(k)
        {
            if(k & 1)
                res *= x;
            k >>= 1, x *= x;
        }

        return res;
    }
};   