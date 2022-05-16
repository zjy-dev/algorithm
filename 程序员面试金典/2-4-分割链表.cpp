#include "LeetCode.h"

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    auto small = new ListNode(0), pSmall = small;
    auto big = new ListNode(0), pBig = big;

    while (head) {
      if (head->val < x) {
        pSmall->next = head;
        pSmall = pSmall->next;
      } else {
        pBig->next = head;
        pBig = pBig->next;
      }

      head = head->next;
    }

    // 接起来
    pSmall->next = big->next;
    pBig->next = NULL;

    return small->next;
  }
};