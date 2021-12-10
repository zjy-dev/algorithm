#include"LeetCode.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        auto ans = new ListNode(0, head);
        auto p = head->next, tail = head;
        while(p)
        {
            if(p->val >= tail->val)
                tail = tail->next;
            else
            {
                auto pre = ans;
                while(pre->next->val < p->val)
                    pre = pre->next;
                
                tail->next = p->next;

                p->next = pre->next;
                pre->next = p;
            }
            p = tail->next;
        }
        return ans->next; 
    }
};