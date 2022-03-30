#include"LeetCode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 计算长度
        int lenA = 0, lenB = 0;
        auto t = headA;
        while (t != NULL) {
            t = t->next;
            lenA++;
        }

        t = headB;
        while (t != NULL) {
            t = t->next;
            lenB++;
        }

        // 保证A短
        if (lenA > lenB) {
            swap(lenA, lenB), swap(headA, headB);
        }

        // B先走lenB - lenA步
        for (int i = 0; i < lenB - lenA; i++) {
            headB = headB->next;
        }

        // 同步后移, 如果不相交会同时为NULL
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};