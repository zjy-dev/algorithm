#include "LeetCode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        // t记录上一个位置的值, 下一个位置的val不能等于t
        int t = head->val;

        auto p = head;
        while (p->next != NULL) {
            // 删除一定要找到想要删除的结点的前一个位置
            if (p->next->val == t) {
                p->next = p->next->next;
                continue;
            }

            // 没重复, 就更新p和t
            t = p->next->val;
            p = p->next;
        } 

        return head;
    }
};