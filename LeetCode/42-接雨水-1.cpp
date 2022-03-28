#include"LeetCode.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0;

        while (l < r) {
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            // 对于l遍历到的某柱子, 我们确切的知道l_max
            // 但r_max不能确定, 因为r可能还未遍历到l + 1的位置
            // 但是此时如果l_max <= r_max, 则真正的r_max有多大都无所谓了
            // 因为此时能装的水量由l_max决定
            if (l_max <= r_max) {
                ans += l_max - height[l++];
            } else { // 对r同理
                ans += r_max - height[r--];
            }
        }

        return ans;
    }
};