#include"LeetCode.h"

class MinStack {
public:
    stack<int> stk1, stk2;
    MinStack() {

    }
    
    void push(int val) {
        stk1.push(val);
        if(stk2.empty() or stk2.top() >= val)
            stk2.push(val);
    }   
    
    void pop() {
        auto t = stk1.top();
        stk1.pop();
        if(stk2.top() == t)
            stk2.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};

