#include"LeetCode.h"

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        if (n == 0) {
            return true;
        }
        
        return dfs(postorder, 0, n - 1);
    }

    bool dfs(vector<int> &arr, int st, int ed) {
        // 空树或单节点的树自然是二叉搜索树
        if (st >= ed) {
            return true;
        }

        // 记录根节点的值, 以此为依据划分左右子树
        int root = arr[ed];

        // 寻找左子树的区间, 用l记录
        int t = st;
        while (arr[t] < root) {
            t++;
        }
        int l = t - 1;

        // 寻找右子树的区间, 用r记录
        while (arr[t] > root) {
            t++;
        }
        int r = t - 1;

        // 如果是正常的二叉搜索树的后序序列的话, root一定是等于r + 1的
        // 如果不是, 说明不是二叉搜索树, 返回false
        if (ed != r + 1) {
            return false;
        }
        
        // 判断左子树和右子树是不是二叉搜索树
        return dfs(arr, st, l) && dfs(arr, l + 1, r);
    }
};