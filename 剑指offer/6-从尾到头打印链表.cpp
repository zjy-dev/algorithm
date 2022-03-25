#include"LeetCode.h"

/**
 * 时间复杂度 -> O(n)
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        // 特判空链表
        if (head == NULL) {
            return {};
        }

        // ans
        vector<int> ans;

        // 反转链表(双指针)
        // p -> head的前一个结点
        ListNode* p = NULL;
        while (head != NULL) {
            // 保存head->next
            ListNode* ne = head->next;

            // 改变head->next指向为向前指
            head->next = p;

            // 更新p和head
            p = head;
            head = ne;
        }

        // 反转后head = NULL, p就是新链表的头结点, 记录答案即可
        while (p != NULL) {
            ans.push_back(p->val);
            p = p->next;
        }

        return ans;
    }
};