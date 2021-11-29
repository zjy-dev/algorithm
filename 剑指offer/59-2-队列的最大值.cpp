#include"LeetCode.h"

class MaxQueue {
public:
    queue<int> q1;
    deque<int> q2;
    MaxQueue() {

    }
    
    int max_value() 
    {
        return q2.empty() ? -1 : q2.front();        
    }
    
    void push_back(int value) 
    {
        q1.push(value);
        while(!q2.empty() and q2.back() < value)
            q2.pop_back();
        q2.push_back(value);
    }
    
    int pop_front() 
    {
        if(q1.empty())
            return -1;
        
        auto ans = q1.front();
        q1.pop();
        if(ans == q2.front())
            q2.pop_front();
        return ans;
    }
};