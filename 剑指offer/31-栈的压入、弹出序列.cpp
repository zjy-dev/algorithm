#include"LeetCode.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> stk;
        int i = 0, n = popped.size();
        for(const auto& val : pushed)
        {
            stk.push(val);
            while(stk.size() and stk.top() == popped[i])
                i++, stk.pop();
        }

        return stk.empty();
    }
};