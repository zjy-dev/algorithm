#include "LeetCode.h"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // 直接用l1作为答案
    auto ans = l1;
    while (l1->next && l2->next) {
      l1->val += l2->val;

      l1->next->val += l1->val / 10;
      l1->val %= 10;

      l1 = l1->next, l2 = l2->next;
    }

    if (l1->next == NULL) {
      l1->next = l2->next;
    }

    l1->val += l2->val;

    while (l1->next) {
      l1->next->val += l1->val / 10;
      l1->val %= 10;
      l1 = l1->next;
    }

    while (l1->val >= 10) {
      l1->next = new ListNode(l1->val / 10);
      l1->val %= 10;
      l1 = l1->next;
    }

    return ans;
  }
};