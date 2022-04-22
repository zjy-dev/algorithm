#include "LeetCode.h"

class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return ans;
    }
    
    // 返回root的深度
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int depL = dfs(root->left);
        int depR = dfs(root->right);

        // 更新ans
        // 直径必然经由某一个结点折返, 而对该结点来说, 知道左右子树深度即可确定该值
        // 也就是depL + depR(看看样例即可)
        // 因此我们遍历每一个结点, 最终就能得到ans
        ans = max(ans, depL + depR);

        // 返回深度
        return max(depL, depR) + 1;
    }
};