#include"LeetCode.h"


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = NULL;

        while (head != NULL) {
            auto ne = head->next;

            head->next = p;

            p = head, head = ne;
        }

        return p;
    }
};