#include "LeetCode.h"

class Solution {
public:
    vector<int> ans;
    vector<int> selfDividingNumbers(int left, int right) {
        for (int i = left; i <= right; i++) {
            if (judge(i) == true) {
                ans.push_back(i);
            }
        }

        return ans;
    }

    bool judge(const int val) {
        int u = val;
        while (u) {
            int t = u % 10;

            // 自除数不允许包含0
            if (t == 0) {
                return false;
            }

            if (val % t != 0) {
                return false;
            }
            u /= 10;
        }

        return true;
    }
};