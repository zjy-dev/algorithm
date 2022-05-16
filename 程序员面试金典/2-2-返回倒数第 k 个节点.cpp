#include "LeetCode.h"

class Solution {
public:
  int kthToLast(ListNode *head, int k) {
    auto p = head;
    while (k--) {
      head = head->next;
    }

    while (head != NULL) {
      head = head->next;
      p = p->next;
    }

    return p->val;
  }
};