#include"LeetCode.h"

const int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

class Solution {
public:
    // 简化dfs的传参
    string str;
    int n, r, c;

    // 要想不走回头路, 就需要vis数组
    vector<vector<bool>> vis;

    bool exist(vector<vector<char>>& board, string word) {
        // 初始化
        str = word, n = str.size();
        r = board.size(), c = board[0].size();
        vis = vector<vector<bool>>(r, vector<bool>(c, false));

        // 以每个位置为开头, 尝试搜索, 搜成功一次即可return true
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (dfs(board, 0, i, j) == true) {
                    return true;
                }
            }
        }

        // 没搜到
        return false;
    }

    bool dfs(vector<vector<char>>& arr, int pos, int x, int y) {
        if (arr[x][y] != str[pos]) { // 路走不通, return false
            return false;
        } 
        
        if (pos == n - 1 && arr[x][y] == str[pos]) {
            // 最后一个字符也一样, return true
            // 注意 "&& arr[x][y] == str[pos]" 可以不写, 这里是为了逻辑清晰
            return true;
        }

        // 防止接下来走回头路而无限递归, 最终导致栈溢出
        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int tx = x + X[i], ty = y + Y[i];
            // 经典校参
            if (tx < 0 || tx >= r || ty < 0 || ty >= c || vis[tx][ty] == true) {
                continue;
            }

            // 这条路走通了, 直接return true, 剪枝
            if (dfs(arr, pos + 1, tx, ty) == true) {
                return true;
            }
        }

        // 回溯法的恢复现场
        vis[x][y] = false;

        // 这条路的所有分路都走不通
        return false;
    }
};