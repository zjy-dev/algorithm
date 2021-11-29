#include"LeetCode.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        return getHeight(root) >= 0;
    }

    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        auto subL = getHeight(root->left), subR = getHeight(root->right);
        if(subL == -1 or subR == -1 or abs(subL - subR) > 1)
            return -1;
        else
            return max(subL, subR) + 1;
    }
};