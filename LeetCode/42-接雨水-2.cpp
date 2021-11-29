#include"LeetCode.h"

class Solution{
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for(int i = 0; i < n; i++)
        {
            while(stk.size() and height[stk.top()] < height[i])
            {
                auto t = stk.top();
                stk.pop();
                if(stk.empty())
                    break;
                
                ans += (i - stk.top() - 1) * (min(height[stk.top()], height[i]) - height[t]);
            }
            stk.push(i);
        }

        return ans;
    }
};