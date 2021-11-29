#include"LeetCode.h"

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        auto p = root;
        while(p or !stk.empty())
        {
            while(p)
                stk.push(p), p = p->left;
            
            p = stk.top(), stk.pop();
            ans.push_back(p->val);
            p = p->right;
        }

        return ans;
    }

};