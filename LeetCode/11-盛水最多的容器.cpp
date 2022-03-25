#include"LeetCode.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));

            // 双指针, 如果移动高的那一边, 那么结果只会变小
            // 而移动矮的那一边, 结果可能变大
            // 因此我们不断移动矮的那一边即可
            if (height[l] < height[r]) {
                l++;
            } else if (height[l] > height[r]) {
                r--;
            } else { // 如果两边高度相等, 那么无论怎么移动都会变小, 所以直接一起移动就好了
                l++, r--;
            }
        }

        return ans;
    }
};