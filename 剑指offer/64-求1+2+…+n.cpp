#include"LeetCode.h"

class Solution {
public:
    int sumNums(int n) {
        // 利用短路来进行递归终点判断
        n && (n += sumNums(n - 1));

        return n;
    }
};