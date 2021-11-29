#include"LeetCode.h"

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto p = head;
        while(k--)
            head = head->next;
        
        while(head)
            head = head->next, p = p->next;
        
        return p;
    }
};