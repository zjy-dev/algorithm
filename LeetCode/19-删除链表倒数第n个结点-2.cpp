#include"LeetCode.h"

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto ans = new ListNode(0, head);
        auto p = ans;
        while(n--)
            head = head->next;
        
        while(head)
            head = head->next, p = p->next;
        
        p->next = p->next->next;
        return ans->next;
    }
};