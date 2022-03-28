#include"LeetCode.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        // while的条件其实十分松散
        // 再加上一个fast->next->next != NULL 也可以
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            // 如果有环, slow和fast都进入环后
            // 每一步fast会与slow的距离缩小1
            // 因此他们一定会相遇
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};