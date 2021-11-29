#include"LeetCode.h"

class Solution {
public:
    unordered_map<int, int> hash;
    vector<int> preorder, inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder, this->inorder = inorder;
        int n = preorder.size();
        for(int i = 0; i < n; i++)
            hash[inorder[i]] = i;
        
        return build(0, n - 1, 0, n - 1);
    }

    TreeNode* build(int preL, int preR, int inL, int inR)
    {
        if(preL > preR)
            return NULL;
        
        int preRoot = preL, inRoot = hash[preorder[preRoot]];

        TreeNode* root = new TreeNode(preorder[preRoot]);
        int subL = inRoot - inL;
        root->left = build(preRoot + 1, preRoot + subL, inL, inRoot - 1);
        root->right = build(preRoot + subL + 1, preR, inRoot + 1, inR);

        return root;
    }
};