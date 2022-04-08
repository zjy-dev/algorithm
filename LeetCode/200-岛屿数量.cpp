#include"LeetCode.h"

// 并查集
class Solution {
public:
    const int X[2] = {0, 1};
    const int Y[2] = {1, 0};
    vector<int> p;

    // 返回p的祖先
    int find(int u) {
        // 路径压缩, 逐级向上, 让u和u的父亲们的父亲直接变成祖先
        // 这样能提高效率
        if (p[u] != u) {
            p[u] = find(p[u]);
        }   

        return p[u];
    }

    // a的祖先的祖先是b的祖先, 也就成功把a和b分为一组了
    // 而且这样频繁的调用find可以保证路径压缩的有效性
    void unionPoint(int a, int b) {
        p[find(a)] = find(b);
    }


    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        p.resize(r * c + 10);

        // 初始化, 每个岛屿的祖先都是自己
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    p[i * c + j] = i * c + j;
                } 
            }
        }

        // 合并操作
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }

                for (int t = 0; t < 2; t++) {
                    int tx = i + X[t], ty = j + Y[t];

                    if (tx < 0 || tx >= r || ty < 0 || ty >= c || grid[tx][ty] == '0') {
                        continue;
                    }

                    unionPoint(tx * c + ty, i * c + j);
                }
            }
        }

        // 看看一共有多少组
        unordered_set<int> s;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                s.insert(find(i * c + j));
            }
        }

        return s.size();
    }
};

// bfs
class Solution {
public: 
    // 如果是bfs就必须四个方向都要, 因为它必须一次性搜到所有相连的'1'
    int X[4] = {1, -1, 0, 0}, Y[4] = {0, 0, 1, -1};

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();

        int ans = 0;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == '0') {
                    continue;
                }

                // 以该点为起点bfs
                queue<pair<int, int>> q;
                q.push({r, c});
                ans++;
                grid[r][c] = '0';

                while (q.empty() == false) {
                    auto t = q.front();
                    q.pop();

                    int x = t.first, y = t.second;
                    for (int t = 0; t < 4; t++) {
                        int tx = x + X[t], ty = y + Y[t];

                        // 寻找周围的'1', 为0或者越界就continue
                        if (tx < 0 || tx >= row || ty < 0 || ty >= col 
                            || grid[tx][ty] == '0') {
                            continue;
                        }

                        grid[tx][ty] = '0';
                        q.push({tx, ty});
                    }
                }
            }
        }

        return ans;
    }
};