#include "LeetCode.h"

class Solution {
public:
  void reverse(ListNode *head, ListNode *tail) {
    auto flag = tail->next;
    ListNode *p = NULL;
    while (head != flag) {
      auto ne = head->next;
      head->next = p;
      p = head;
      head = ne;
    }
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    auto ans = new ListNode(0, head);
    auto pre = ans;
    while (true) {
      auto tail = pre;
      for (int i = 0; i < k; i++) {
        tail = tail->next;
        if (!tail)
          return ans->next;
      }

      auto ne = tail->next;
      reverse(head, tail);
      swap(head, tail);

      //将反转后的子链表接回原链表
      pre->next = head;
      tail->next = ne;

      //更新
      pre = tail;
      head = ne;
    }

    return ans->next;
  }
};