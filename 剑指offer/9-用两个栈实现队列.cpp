#include"LeetCode.h"


class CQueue {
public:
    stack<int> s1, s2;
    CQueue() {}
    
    void appendTail(int val) {
        s1.push(val);
    }
    
    int deleteHead() {
        if(s2.empty())
            while(s1.size())
                s2.push(s1.top()), s1.pop();
        if(s2.size())
        {
            auto ans = s2.top();
            s2.pop();
            return ans;
        }
        else
            return -1;
    }
};