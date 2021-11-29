#include"LeetCode.h"

class Solution {
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

    bool isPalindrome(ListNode* head) {
        auto slow = head, fast = head;
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //分隔成两个链表
        auto temp = reverseList(slow->next);
        
        for(; temp; temp = temp->next, head = head->next)
            if(temp->val != head->val)
                return false;
        
        return true;
    }
};