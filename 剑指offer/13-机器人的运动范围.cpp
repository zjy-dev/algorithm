#include"LeetCode.h"

const int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

class Solution {
public:
    vector<vector<bool>> vis;
    int ans = 0;

    int movingCount(int m, int n, int k) {
        vis = vector<vector<bool>>(m, vector<bool>(n, false));

        // 预处理不能走的格子
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = !judge(k, i, j);
            }
        }

        // (0, 0)格也要判断一下能不能走
        if (vis[0][0] == false) {
            dfs(0, 0, m, n);
        }

        return ans;
    }

    void dfs(int x, int y, const int m, const int n) {
        // 这个格子走过了, 标记一下
        ans++;
        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int tx = x + X[i], ty = y + Y[i];

            // 遇到vis = true的格子就停下
            // 不用担心漏答案, 第一次走到这个格子的路线早就考虑过走到这个格子后的所有情况了
            if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty]) {
                continue;
            }

            dfs(tx, ty, m, n);
        }
    }

    // 有手就行的judge函数
    bool judge(int k, int x, int y) {
        int cnt = 0;
        while (x != 0) {
            cnt += (x % 10);
            x /= 10;
        }

        while (y != 0) {
            cnt += (y % 10);
            y /= 10;
        }

        return cnt <= k;
    }
};