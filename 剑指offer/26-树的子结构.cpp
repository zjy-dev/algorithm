#include"LeetCode.h"

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        return (A and B) and 
        (dfs(A, B) or isSubStructure(A->left, B) or isSubStructure(A->right, B));
    }

    bool dfs(TreeNode* A, TreeNode* B)
    {
        if(!B)
            return true;

        if(!A or A->val != B->val)
            return false;
        
        return dfs(A->left, B->left) and dfs(A->right, B->right);
    }
};