#include "LeetCode.h"

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    auto ans = new ListNode(0, head), p = ans;
    while (p->next and p->next->next) {
      auto ne = head->next->next;

      p->next = head->next;
      head->next->next = head;
      head->next = ne;

      p = head;
      head = ne;
    }

    return ans->next;
  }
};