#include"LeetCode.h"

class Solution{
public:
    unordered_map<Node*, Node*> hash;

    Node* copyRandomList(Node* head) 
    {
        return dfs(head);
    }

    Node* dfs(Node* node)
    {
        if(!node or hash[node])
            return hash[node];

        hash[node] = new Node(node->val);
        hash[node]->next = dfs(node->next);
        hash[node]->random = dfs(node->random);
        return hash[node];
    }
};

