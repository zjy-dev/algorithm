#include"LeetCode.h"

class Solution {
public:
    Node* head = NULL, *tail = NULL;
    Node* treeToDoublyList(Node* root) 
    {
        dfs(root);
        head->left = tail, tail->right = head;
        return head;
    }

    void dfs(Node* root)
    {
        if(!root)
            return;
        
        dfs(root->left);
        root->left = tail;
        if(tail)
            tail->right = root;
        else
            head = root;
        
        tail = root; //tail后移
        dfs(root->right);
    }
};

