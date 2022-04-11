#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        if (root == NULL) {
            return {};
        }
        
        vector<int> v;
        dfs(v, tar, root);

        return ans;
    }

    void dfs(vector<int> &v, int tar, TreeNode* root) {
        // 叶子结点作为搜索的边界
        if (root->left == NULL && root->right == NULL) {
            // 判断是否成立
            if (tar == root->val) {
                v.push_back(tar);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }

        // 将tar剪去根节点的值, 然后向左右子树递归搜索
        tar -= root->val;
        if (root->left != NULL) {
            // 回溯算法, 一定要pop_back()
            v.push_back(root->val);
            dfs(v, tar, root->left);
            v.pop_back();
        }

        if (root->right != NULL) {
            v.push_back(root->val);
            dfs(v, tar, root->right);
            v.pop_back();
        }
    }


};