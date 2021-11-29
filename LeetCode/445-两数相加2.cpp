#include"LeetCode.h"

class Solution{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p = NULL;
        while(head)
        {
            auto ne = head->next;
            head->next = p;
            p = head, head = ne;
        }
        return p;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1), l2 = reverseList(l2);
        auto ans = l1;
        while(l1->next and l2->next)
        {
            l1->val += l2->val;
            l1->next->val += l1->val / 10;
            l1->val %= 10;
            l1 = l1->next, l2 = l2->next;
        }

        l1->val += l2->val;

        if(l2->next)
            l1->next = l2->next;
        
        while(l1->next)
        {
            l1->next->val += l1->val / 10;
            l1->val %= 10;
            l1 = l1->next;
        }

        while(l1->val >= 10)
        {
            l1->next = new ListNode(l1->val / 10, NULL);
            l1->val %= 10;
            l1 = l1->next;
        }
        
        return reverseList(ans);
    }
};