#include "LeetCode.h"

/**
 * 时间复杂度 -> O(n)
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
  ListNode *deleteNode(ListNode *head, int val) {
    // 考虑到删除头结点的情况, 加一个伪头结点能消除不一致性
    auto ans = new ListNode(0, head);

    auto p = ans;
    while (p->next != NULL) {
      if (p->next->val == val) {
        p->next = p->next->next;
        break;
      }
      p = p->next;
    }
    return ans->next;
  }
};