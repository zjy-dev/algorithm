#include"LeetCode.h"

/**
 * 时间复杂度 => O(n), 每个结点只会被搜索一次
 * 空间复杂度 => O(n), 要维护一个队列用于bfs 
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<vector<int>> ans;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // 使用双端队列以满足"之字形"的需求
            deque<int> d;

            // 为了取一层的数据, 也就是取q.size()个数据, 要使用循环
            // 且因为q.size()是动态变化的, 所以要读取初始的q.size(), 然后倒着循环
            for (int i = q.size(); i != 0; i--) {
                auto t = q.front();
                q.pop();

                // 根据flag判断方向
                if (flag == true) {
                    d.push_back(t->val);
                } else {
                    d.push_front(t->val);
                }

                if (t->left != NULL) {
                    q.push(t->left);
                }
                if (t->right != NULL) {
                    q.push(t->right);
                }
            }

            vector<int> v;
            while (!d.empty()) {
                v.push_back(d.front());
                d.pop_front();
            }
            ans.push_back(v);
            flag = !flag;
        }

        return ans;
    }
};