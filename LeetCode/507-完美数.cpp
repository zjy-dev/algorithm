#include"LeetCode.h"


class Solution {
public:
    bool checkPerfectNumber(int num) 
    {
        if(num == 1)
            return false;
        
        int s = 1;

        for(int i = 2; i * i <= num; i++)
            if(num % i == 0)
            {
                s += i;
                if(i * i != num)
                    s += (num / i);
            }

        return s == num;
    }
};  