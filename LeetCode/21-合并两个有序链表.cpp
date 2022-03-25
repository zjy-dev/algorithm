#include"LeetCode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto ans = new ListNode();
        auto p = ans;

        // 相当于双指针, 判断哪个更小一点, 串起来
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

        // 别忘了收尾
        p->next = (l1 == NULL ? l2 : l1);

        return ans->next;
    }
};