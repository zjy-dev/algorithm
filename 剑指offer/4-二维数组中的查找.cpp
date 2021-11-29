#include"LeetCode.h"

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int tar) {
        int row = matrix.size();
        if(!row)
            return false;
        int col = matrix[0].size();
        int i = 0, j = col - 1;
        while(i < row and j >= 0)
        {
            if(matrix[i][j] == tar)
                return true;

            if(matrix[i][j] > tar)
                j--;
            else
                i++;
        }

        return false;
    }
};