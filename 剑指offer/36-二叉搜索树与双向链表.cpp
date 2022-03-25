#include"LeetCode.h"

class Solution {
public: 
    Node *head = NULL, *tail = NULL;
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        // 串成双向链表
        dfs(root);

        // 串成循环链表
        head->left = tail;
        tail->right = head;

        return head;
    }

    // 将root串成双向链表, 并和已经串好的链表串在一起
    void dfs(Node* root) {
        if (root == NULL) {
            return;
        }

        // 先串好左子树(会更新head和tail)
        dfs(root->left);

        if (tail == NULL) { 
            // 如果尾结点(或头结点)为空, 说明头结点和尾结点都是root
            head = root;
            tail = root;
        } else {
            // 如果尾结点非空, 就利用二叉搜索树左子树val小于根节点val的特点
            // 更新一下此双向链表
            tail->right = root;
            root->left = tail;
            // tail别忘记后移, 容易忘!
            tail = tail->right;
        }

        // 将root->right串成双向链表, 并和已经串好的链表串在一起
        dfs(root->right);
    }
};

