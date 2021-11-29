#include"LeetCode.h"

class Solution{
public:
    int largestRectangleArea(vector<int>& nums) 
    {
        int n = nums.size();
        stack<int> stk;
        stk.push(-1);
        int ans = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            while(stk.top() != -1 and nums[stk.top()] >= nums[i])
            {
                int height = nums[stk.top()];
                stk.pop();
                int len = i - stk.top() - 1;
                ans = max(ans, len * height);
            }
            stk.push(i);
        }

        while(stk.top() != -1)
        {
            int height = nums[stk.top()];
            stk.pop();
            int len = n - stk.top() - 1;
            ans = max(ans, len * height);
        }   

        return ans;
    }
};