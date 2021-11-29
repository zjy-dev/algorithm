#include"LeetCode.h"

class Solution{
public:
    int climbStairs(int n) {
        if(n < 2)
            return 1;
        n--;
        int a = 1, b = 1;
        while(n--)
        {
            auto t = a;
            a = b;
            b += t;
        }

        return b;
    }
};