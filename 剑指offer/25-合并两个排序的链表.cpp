#include"LeetCode.h"

/**
 * 时间复杂度 -> O(n), 双指针
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto ans = new ListNode(0);
        auto p = ans;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }

            p = p->next;
        }

        p->next = (l1 != NULL ? l1 : l2);

        return ans->next;
    }
};