#include"LeetCode.h"

/**
 * 时间复杂度 -> O(n), 双指针
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 双指针, p先走k步, 然后同步移动p和head, p为NULL时head就是倒数第k个结点了
        ListNode* p = head;

        // 为什么while(k--)是正确的? 可以用样例模拟一下
        while (k--) {
            p = p->next;
        }

        // 同步后移即可
        while (p != NULL) {
            head = head->next;
            p = p->next;
        }

        return head;
    }
};