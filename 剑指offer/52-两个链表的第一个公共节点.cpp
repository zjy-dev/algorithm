#include"LeetCode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA), lenB = getLen(headB);

        // 让lenA >= lenB
        if (lenA < lenB) {
            return getIntersectionNode(headB, headA);
        } 

        // A先往后走lenA - lenB步
        for (int i = lenA - lenB; i != 0; i--) {
            headA = headA->next;
        }

        // 共同往后走, 直到找到相同的结点
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }

    int getLen(ListNode *head) {
        int ans = 0;
        while (head != NULL) {
            head = head->next;
            ans++;
        }

        return ans;
    }
};