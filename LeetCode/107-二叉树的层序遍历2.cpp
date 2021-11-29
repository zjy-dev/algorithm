#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> ans;
    stack<vector<int>> temp;
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if(!root)
            return {};
        bfs(root);
        return ans;
    }

    void bfs(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int n = q.size();
            vector<int> v;
            for(int i = 0; i < n; i++)
            {
                auto t = q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            temp.push(v);
        }
        while(temp.size())
            ans.push_back(temp.top()), temp.pop();
    }
};