#include"LeetCode.h"

class Solution{
public:
    int getLen(ListNode* head)
    {
        int ans = 0;
        for(; head; head = head->next, ans++);
        return ans;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto lenA = getLen(headA), lenB = getLen(headB);
        if(lenA > lenB)
            swap(headA, headB), swap(lenA, lenB);
        
        for(int i = 0; i < lenB - lenA; i++)
            headB = headB->next;
        while(headA != headB)
            headA = headA->next, headB = headB->next;
        
        return headA;
    }
};