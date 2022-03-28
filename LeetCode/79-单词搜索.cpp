#include"LeetCode.h"

class Solution {
public:
    const int X[4] = {0, 0, 1, -1};
    const int Y[4] = {1, -1, 0, 0};
    vector<vector<bool>> vis;
    string s;
    int row, col;
    bool exist(vector<vector<char>>& arr, string word) {
        this->s = word;
        this->row = arr.size(), this->col = arr[0].size();

        vis = vector<vector<bool>>(row + 1, vector<bool>(col + 1, false));

        // 尝试以每个位置为起点进行dfs
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // 只要一个位置成功了, 就是真的成功了, 直接return
                if (dfs(arr, i, j, 0) == true) {
                    return true;
                }
            }
        }

        // 所有位置都没成功, return false
        return false;
    }

    bool dfs(vector<vector<char>>& arr, int r, int c, int idx) {
        // 递归边界
        if (idx == s.size() - 1 && s[idx] == arr[r][c]) {
            return true;
        }

        // 剪枝, 此路不通
        if (arr[r][c] != s[idx]) {
            return false;
        }

        vis[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int tx = r + X[i], ty = c + Y[i];

            // 经典dfs
            if (tx < 0 || tx >= row || ty < 0 || ty >= col || vis[tx][ty]) {
                continue;
            }
            if (dfs(arr, tx, ty, idx + 1) == true) {
                return true;
            }
        }

        // 回溯法, 恢复现场
        vis[r][c] = false;

        // 所有路都没走通
        return false;
    }
};