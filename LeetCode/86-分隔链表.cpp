#include "LeetCode.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // dummy1记录小于x的数, dummy2反之
        auto dummy1 = new ListNode(0);
        auto t1 = dummy1;
        auto dummy2 = new ListNode(0);
        auto t2 = dummy2;

        // 按需接入dummy1或者2
        auto p = head;
        while (p) {
            if (p->val < x) {
                t1->next = p;
                t1 = t1->next;
            } else {
                t2->next = p;
                t2 = t2->next;
            }

            p = p->next;
        }

        // 把大的接在小的后面
        t1->next = dummy2->next;
        // 大的表尾指空
        t2->next = NULL;

        return dummy1->next;
    }
};