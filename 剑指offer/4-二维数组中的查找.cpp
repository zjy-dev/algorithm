#include"LeetCode.h"

/**
 * 时间复杂度 -> O(n), 最多指针也就移动row + col次
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 根据题目范围, 需要特判
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        // row -> 行, col -> 列
        int row = matrix.size(), col = matrix[0].size();

        // 从右上角(或者左下角)开始找, 这样才能根据当前值的大小唯一的更新指针
        // 若从左上角(或右下角)开始找, 则会有二义性
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (matrix[i][j] < target) {
                i++;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                return true;
            }
        }

        return false;
    }
};