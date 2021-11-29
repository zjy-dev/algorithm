#include"LeetCode.h"

typedef long long LL;
const int mod = 1e+9 + 7;

class Solution {
public:
    int cuttingRope(int n) 
    {
        if(n < 2)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        
        int num_3 = n / 3;
        if(n % 3 == 1)
            num_3--;
        
        return quick_mi(3, num_3, mod) * (LL)pow(2, (n - num_3 * 3) / 2) % mod;
    }

    int quick_mi(int m, int k, int p)
    {
        int res = 1 % p, t = m;
        while (k)
        {
            if (k & 1) 
                res = (LL)res * t % p;
            t = (LL)t * t % p;
            k >>= 1;
        }
        return res;
    }
};