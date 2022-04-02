#include "LeetCode.h"

class Solution {
public:

    // 获取链表长度并返回尾结点
    pair<int, ListNode*> getLen(ListNode* p) {
        int ans = 0;
        while (p->next != NULL) {
            p = p->next;
            ans++;
        }

        return {ans + 1, p};
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }

        // 链表长度和尾结点
        int n;
        ListNode* tail;
        auto t = getLen(head);
        n = t.first, tail = t.second;

        // 旋转的次数是n的倍数, 就相当于无需旋转
        if (k % n == 0) {
            return head;
        }

        // 否则要取模n
        k %= n;

        // 找到断开的位置(p和p->next就是分界处)
        auto p = head;
        for (int i = 0; i < n - k - 1; i++) {
            p = p->next;
        }

        // 要返回的头结点ans就是p->next
        auto ans = p->next;

        // p是新的尾结点, 将next置为NULL
        p->next = NULL;

        // 原尾结点接到原头结点上
        tail->next = head;

        // 返回新头结点
        return ans;
    }
};