#include"LeetCode.h"

class Solution {
public:
    vector<int> inorder, postorder;
    unordered_map<int, int> hash;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        this->inorder = inorder, this->postorder = postorder;
        int n = inorder.size();
        for(int i = 0; i < n; i++)
            hash[inorder[i]] = i;
        return dfs(0, n - 1, 0, n - 1);
    }

    TreeNode* dfs(int inL, int inR, int pL, int pR)
    {
        if(inL > inR)
            return NULL;
        auto root = new TreeNode(postorder[pR]);
        auto p = hash[root->val];
        int lenL = p - inL;
        root->left = dfs(inL, p - 1, pL, pL + lenL - 1);
        root->right = dfs(p + 1, inR, pL + lenL, pR - 1);
        return root;
    }
};