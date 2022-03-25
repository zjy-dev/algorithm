#include"LeetCode.h"

/**
 * 属实没搞明白这题是干嘛
 */
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;

        // 发生甚么事了, 这么福利???
        int maxNum = pow(10, n);
        for (int i = 1; i < maxNum; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};