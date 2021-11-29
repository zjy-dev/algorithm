#include"LeetCode.h"

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p = head, ans = head;
        while(n--)
            head = head->next;

        if(!head)
            return ans->next;

        while(head->next)
            head = head->next, p = p->next;

        p->next = p->next->next;
        return ans;
    }
};

