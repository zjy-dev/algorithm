#include"LeetCode.h"

class Solution {
public:
    int add(int a, int b) 
    {
        //没有进位了, 停止迭代
        while(b)
        {
            //c为a, b的进位和
            int c = (unsigned)(a & b) << 1;
            //a为无进位和
            a ^= b;
            //b为进位和
            b = c;
        }

        return a;
    }
};