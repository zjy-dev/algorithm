#include"LeetCode.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 1.沿着水平轴翻转
        for (int r = 0; r < (n >> 1); r++) {
            for (int c = 0; c < n; c++) {
                swap(matrix[r][c], matrix[n - r - 1][c]);
            }
        }

        // 2.沿着主对角线翻转(左上--右下)
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < r; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

    }
};