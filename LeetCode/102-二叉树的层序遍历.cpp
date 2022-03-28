#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (q.empty() == false) {
            int t = q.size();
            vector<int> temp;

            // 直接遍历一层t个结点
            for (int i = 0; i < t; i++) {
                auto node = q.front();
                temp.push_back(node->val);
                q.pop();

                // 非空才push
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};