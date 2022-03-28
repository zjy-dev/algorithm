#include"LeetCode.h"

/**
 * 时间复杂度 => O(n), 一次遍历
 * 空间复杂度 => O(n), 单调栈
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        // 单调栈, 单调递减
        // 这是为了轻松找到栈顶柱子左边第一个比栈顶柱子高的柱子
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            // 维护栈单调递减, 同时更新ans
            while (!stk.empty() && height[stk.top()] <= height[i]) {
                auto t = stk.top();
                stk.pop(); 

                // 根据题干, 边界不能盛水
                if (stk.empty() == true) {
                    break;
                }

                // stk.top()就是t左边第一个比t高的柱子
                int wid = i - stk.top() - 1;
                int hei = min(height[i], height[stk.top()]) - height[t];
                ans += wid * hei;
            }

            stk.push(i);
        }

        return ans;
    }
};