#include"LeetCode.h"

class Solution {
public:
    vector<bool> row, col, dg, udg;
    int n, ans = 0;

    void dfs(int i, int j, int cnt)
    {
        if(j == n)
            j = 0, i++;

        if(i == n)
        {
            if(cnt == n)
                ans++;
            return;
        }

        //不放皇后
        dfs(i, j + 1, cnt);

        //放皇后
        if(!row[i] and !col[j] and !dg[i - j + n] and !udg[i + j])
        {
            row[i] = col[j] = dg[i - j + n] = udg[i + j] = true;
            dfs(i, j + 1, cnt + 1);
            row[i] = col[j] = dg[i - j + n] = udg[i + j] = false;
        }
    }

    int totalNQueens(int n) 
    {
        this->n = n;
        row.resize(n, false);
        col.resize(n, false);
        dg.resize(2 * n, false);
        udg.resize(2 * n, false);

        dfs(0, 0, 0);

        return ans;
    }
};