#include"LeetCode.h"

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        auto cur = root;
        TreeNode* ans = NULL;

        while(cur)
            if(cur->val > p->val)
                ans = cur, cur = cur->left;
            else
                cur = cur->right;

        return ans;
    }
};