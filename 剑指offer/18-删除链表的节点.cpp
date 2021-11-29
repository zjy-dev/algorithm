#include"LeetCode.h"

class Solution{
public:
    ListNode* deleteNode(ListNode* head, int val) {
        auto ans = new ListNode(0, head);
        for(auto p = ans; p->next; p = p->next)
            if(p->next->val == val)
            {
                p->next = p->next->next;
                break;
            }
        
        return ans->next;
    }
};