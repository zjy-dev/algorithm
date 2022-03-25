#include "LeetCode.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;

        // 栈的size == 1时, 存放最后一个不合法右括号下标
        // size > 1时, 栈底依然是 最后一个不合法右括号下标, 其他元素是左括号下标
        // 栈中元素都不合法, 都没有配偶
        stack<int> stk;

        // 因此要初始化为-1
        stk.push(-1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') { // 单独的左括号, 肯定不合法
                stk.push(i);
            } else {
                stk.pop();  

                if (stk.empty()) { // 如果pop后为空, 则更新最后一个不合法右括号下标
                    stk.push(i);
                } else { // 非空, 说明刚才和左括号匹配了, 更新答案即可
                    // pop后的stk.top()是最后一个不合法元素
                    ans = max(ans, i - stk.top());
                }
            }
        }

        return ans;
    }
};