#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int tar) {
        vector<vector<int>> ans;

        // cnt维护窗口内值的总和
        int cnt = 0;

        // fast的值在窗口里面, 因为每次都是cnt += ++fast
        // slow的值在窗口外卖, 因为每次 cnt -= ++slow都会把slow减出窗口
        int slow = 0, fast = 0;

        // 双指针, 维护cnt窗口
        while (slow + fast <= tar) {
            if (cnt < tar) {
                cnt += ++fast;
            } else if (cnt > tar) {
                cnt -= ++slow;
            } else {
                vector<int> temp;
                // 别忘了slow不在窗口里
                for (int i = slow + 1; i <= fast; i++) {
                    temp.push_back(i);
                }

                ans.push_back(temp);

                // 记录答案后要更新指针和窗口, 不然会无限循环
                cnt += ++fast;
                cnt -= ++slow;
            }
        }

        return ans;
    }
};