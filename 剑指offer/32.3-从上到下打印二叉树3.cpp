#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool flag = true;
        q.push(root);

        while(q.size())
        {
            deque<int> temp;
            for(int i = q.size(); i; i--)
            {
                auto t = q.front();
                q.pop();
                flag ? temp.push_back(t->val) : temp.push_front(t->val);

                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            vector<int> v;
            while(temp.size())
                v.push_back(temp.front()), temp.pop_front();
            ans.push_back(v), flag = !flag;
        }
        return ans;
    }
};