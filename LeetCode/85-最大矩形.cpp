#include"LeetCode.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> pre(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == '1')
                    pre[i][j] = (j ? pre[i][j - 1] + 1 : 1);

        int ans = INT_MIN;

        for(int c = 0; c < n; c++)
        {
            stack<int> stk;
            stk.push(-1);

            for(int r = 0; r < m; r++)
            {
                while(stk.top() != -1 and pre[stk.top()][c] >= pre[r][c])
                {
                    int height = pre[stk.top()][c];
                    stk.pop();
                    int len = r - stk.top() - 1;
                    ans = max(ans, height * len);
                }
                stk.push(r);
            }

            while(stk.top() != -1)
            {
                int height = pre[stk.top()][c];
                stk.pop();
                int len = m - stk.top() - 1;
                ans = max(ans, height * len);
            }
        }

        return ans;      
    }
};  