#include "LeetCode.h"

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    auto ans = new ListNode(0, head);
    auto p = ans;
    while (p->next)
      if (p->next->val == val)
        p->next = p->next->next;
      else
        p = p->next;
    return ans->next;
  }
};