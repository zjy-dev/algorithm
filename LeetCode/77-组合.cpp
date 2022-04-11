#include "LeetCode.h"

class Solution {
public:
    int n, k;
    vector<vector<int>> ans;
    vector<int> temp;
    
    vector<vector<int>> combine(int n, int k) {
        this->n = n, this->k = k;
        dfs(1);

        return ans;
    }

    void dfs(int idx) {
        // 达到k个数了
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // 边界 || 剪枝
        if (idx > n || n - idx + 1 + temp.size() < k) {
            return;
        }

        // 选idx
        temp.push_back(idx);
        dfs(idx + 1);
        temp.pop_back();

        // 不选
        dfs(idx + 1);
    }
};