#include"LeetCode.h"

class MinStack {
public:
    // 用stk1来正常的维护一个栈
    // stk2则用来维护最小值
    stack<int> stk1, stk2;

    MinStack() {

    }
    
    void push(int x) {
        stk1.push(x);
        if (stk2.empty() || stk2.top() >= x) {
            stk2.push(x);
        }
    }
    
    void pop() {
        int t = stk1.top();
        stk1.pop();

        if (stk2.top() == t) {
            stk2.pop();
        }
    }
    
    int top() {
        return stk1.top();
    }
    
    int min() {
        return stk2.top();
    }
};

