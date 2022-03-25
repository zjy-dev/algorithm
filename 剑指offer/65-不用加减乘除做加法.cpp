#include"LeetCode.h"

class Solution {
public:
    int add(int a, int b) {

        // 进位为0就可以结束了
        while (b != 0) {
            // c为无进位和
            int c = (unsigned)(a & b) << 1;
            
            // a为无进位和
            a ^= b;

            // b更新为进位
            b = c;
        }

        return a;
    }
};