#include "LeetCode.h"

class Solution {
public:
  void reverseList(ListNode *head, ListNode *tail) {
    ListNode *p = NULL, *ed = tail->next;
    while (head != ed) {
      auto ne = head->next;
      head->next = p;
      p = head, head = ne;
    }
  }

  ListNode *reverseBetween(ListNode *head, int left, int right) {
    auto ans = new ListNode(0, head);
    int n = right - left;
    auto p = head;
    ListNode *pre = ans;
    while (left > 1)
      left--, pre = p, p = p->next;
    auto hh = p;
    while (n--)
      p = p->next;
    auto tail = p->next;
    reverseList(hh, p);

    pre->next = p, hh->next = tail;

    return ans->next;
  }
};