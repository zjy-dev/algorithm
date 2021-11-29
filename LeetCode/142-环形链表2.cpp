#include"LeetCode.h"

class Solution{
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                auto p = head;
                while(p != slow)
                    p = p->next, slow = slow->next;
                return p;
            }
        }

        return NULL;
    }
};