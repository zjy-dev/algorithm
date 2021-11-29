#include"LeetCode.h"

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        while(head)
            stk.push(head->val), head = head->next;
        int n = stk.size();
        vector<int> ans;
        while(!stk.empty())
            ans.push_back(stk.top()), stk.pop();
            
        return ans;
    }
};