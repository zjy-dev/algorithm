#include "LeetCode.h"

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    auto slow = head, fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow) {
        auto p = head;
        while (slow != p) {
          slow = slow->next;
          p = p->next;
        }
        return p;
      }
    }

    return NULL;
  }
};