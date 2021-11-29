#include"LeetCode.h"

class Solution{
public:
    vector<int> asteroidCollision(vector<int> nums) {
        stack<int> stk;
        for(const auto& val : nums)
        {
            if(val > 0)
            {
                stk.push(val);
                continue;
            }

            while(!stk.empty() and stk.top() > 0 and -val > stk.top())
                stk.pop();

            if(stk.empty() or stk.top() < 0)
                stk.push(val);
            else if(!stk.empty() and stk.top() == -val)
                stk.pop();
        }

        int n = stk.size();
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; i--)
            ans[i] = stk.top(), stk.pop();
        return ans;
    }
};

