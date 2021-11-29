#include"LeetCode.h"

class Solution {
public:
    vector<int> preorder, inorder;
    unordered_map<int, int> hash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        this->preorder = preorder, this->inorder = inorder;
        for(int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;
        return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* dfs(int preL, int preR, int midL, int midR)
    {
        if(preL > preR)
            return NULL;
        auto root = new TreeNode(preorder[preL]);
        int p = hash[root->val];
        int lenL = p - midL;
        root->left = dfs(preL + 1, preL + lenL, midL, p - 1);
        root->right = dfs(preL + lenL + 1, preR, p + 1, midR);
        return root; 
    }
};