#include"LeetCode.h"

class Solution{
public:
    const int mod = 1000000007;
    int fib(int n)
    {
        if(n < 2)
            return n;
        n -= 1;
        int a = 0, b = 1;
        while(n--)
        {
            int t = a;
            a = b;
            b = (b + t) % mod;
        }

        return b;
    }
};

int main(int argc, char const *argv[])
{
    printf("aaa");
    return 0;
}

