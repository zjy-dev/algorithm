#include"LeetCode.h"

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        auto p = root;
        while(p)
        {
            if(p->left)
            {
                auto tailL = p->left;
                while(tailL->right)
                    tailL = tailL->right;
                tailL->right = p->right;

                p->right = p->left;
                p->left = NULL;
            }

            p = p->right;
        }
    }
};  