#include"LeetCode.h"

const int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

class Solution {
public:
    vector<vector<bool>> vis;
    int k, m, n, ans = 0;
    int movingCount(int m, int n, int k) 
    {
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        this->k = k, this->m = m, this->n = n;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                vis[i][j] = !judge(i, j);
        if(!vis[0][0])
            dfs(0, 0);
        return ans;
    }   

    void dfs(int i, int j)
    {
        ans++;
        vis[i][j] = true;
        for(int t = 0; t < 4; t++)
        {
            auto x = i + X[t], y = j + Y[t];
            if(x < 0 or x >= m or y < 0 or y >= n or vis[x][y])
                continue;
            
            dfs(x, y);
        }
    }

    bool judge(int r, int c)
    {
        int temp = 0;
        while(r)
        {
            temp += r % 10;
            r /= 10;
        }

        while(c)
        {
            temp += c % 10;
            c /= 10;
        }

        return temp <= k;
    }
};