#include "LeetCode.h"

/**
 * 时间复杂度 -> O(n), 双指针
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    // 双指针
    ListNode *p = NULL;

    while (head != NULL) {
      // 保存一下head的后一个结点
      ListNode *ne = head->next;

      // 反转链表
      head->next = p;

      // 双指针同步后移
      p = head, head = ne;
    }

    return p;
  }
};