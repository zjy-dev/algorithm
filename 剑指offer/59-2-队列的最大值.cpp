#include"LeetCode.h"

class MaxQueue {
public:

    // 普通的队列, 实现基本功能
    queue<int> q1;

    // 递减的单调队列(可重复), 不断的对他进行维护, 这样q2的队首就是最大值
    deque<int> q2;

    MaxQueue() {

    }
    
    int max_value() {
        // 根据题干, 空队列返回-1
        if (q2.empty()) {
            return -1;
        }

        return q2.front();
    }
    
    void push_back(int value) {
        q1.push(value);

        // 维护单调队列
        while (q2.empty() == false && q2.back() < value) {
            q2.pop_back();   
        }

        q2.push_back(value);
    }
    
    int pop_front() {
        if (q1.empty()) {
            return -1;
        }

        int ans = q1.front();
        q1.pop();

        // 维护单调队列
        if (ans == q2.front()) {
            q2.pop_front();
        }

        return ans;
    }
};

