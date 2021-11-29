#include"LeetCode.h"

class MinStack {
public:
    stack<int> stk1, stk2;
    MinStack() {}
    
    void push(int x) 
    {
        stk1.push(x);
        if(stk2.empty() or stk2.top() >= stk1.top())
            stk2.push(x);
    }
    
    void pop() 
    {
        auto t = stk1.top();
        stk1.pop();
        if(t == stk2.top())
            stk2.pop();
    }
    
    int top() 
    {
        return stk1.top();
    }
    
    int min() 
    {
        return stk2.top();
    }
};