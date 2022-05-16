#include "LeetCode.h"

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *p = NULL;
    while (head) {
      auto ne = head->next;
      head->next = p;
      p = head, head = ne;
    }

    return p;
  }

  void mergeList(ListNode *l1, ListNode *l2) {
    auto ans = new ListNode(0, 0);
    auto p = ans;
    while (l2) {
      p->next = l1, p = p->next;
      l1 = l1->next;

      p->next = l2, p = p->next;
      l2 = l2->next;
    }
    p->next = l1;
  }

  void reorderList(ListNode *head) {
    if (!head)
      return;

    auto slow = head, fast = head;
    while (fast->next and fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    //分隔成两个链表
    auto temp = reverseList(slow->next);
    slow->next = NULL;

    mergeList(head, temp);
  }
};