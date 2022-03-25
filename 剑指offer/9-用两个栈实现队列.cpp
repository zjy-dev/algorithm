#include"LeetCode.h"

class CQueue {
public:
    // 两个栈
    stack<int> stk1, stk2;
    
    // push就直接往stk1里push即可
    void appendTail(int value) {
        stk1.push(value);
    }
    
    // pop要分情况讨论, 基本思路是将stk1通过stk2翻个底朝天
    int deleteHead() {
        if (stk2.size() != 0) { // 如果stk2还没出完队, 就直接出队
            int ans = stk2.top();
            stk2.pop();
            return ans;
        } else if (stk1.size() != 0) { // 否则如果stk1中有元素, 就翻个底朝天, 然后出队
            while (!stk1.empty()) {
                int t = stk1.top();
                stk1.pop();
                stk2.push(t);
            }
            // 投机取巧行为
            return deleteHead();
        }

        // 空队列, 根据题目要求返回-1
        return -1;
    }
};