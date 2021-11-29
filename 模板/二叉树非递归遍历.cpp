// #include"LeetCode.h"

// class Solution{
// public:
//     vector<int> 中序遍历(TreeNode* root) {
//         stack<TreeNode*> stk;
//         vector<int> ans;
//         auto p = root;
//         while(p or !stk.empty())
//         {
//             while(p)
//                 stk.push(p), p = p->left;
            
//             p = stk.top(), stk.pop();
//             ans.push_back(p->val);
//             p = p->right;
//         }
//         return ans;
//     }

//     vector<int> 前序遍历(TreeNode* root) {
//         stack<TreeNode*> stk;
//         vector<int> ans;
//         auto p = root;
//         while(p or !stk.empty())
//         {
//             while(p)
//             {
//                 ans.push_back(p->val);
//                 stk.push(p), p = p->left;
//             }
            
//             p = stk.top(), stk.pop();
//             p = p->right;
//         }
//         return ans;
//     }

//     vector<int> 后序遍历(TreeNode* root) {
//         vector<int> ans;
//         stack<TreeNode*> stk;
//         auto p = root;
//         TreeNode* prev = NULL;

//         while(p or !stk.empty())
//         {
//             while(p)
//                 stk.push(p), p = p->left;
            
//             p = stk.top();
//             if(p->right and p->right != prev)
//                 p = p->right;
//             else
//             {
//                 stk.pop();
//                 ans.push_back(p->val);
//                 prev = p;
//                 p = NULL;
//             }
//         }
//     }
    
// };