#include "LeetCode.h"

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head == NULL) {
      return true;
    }

    // 分割成两个链表
    // slow->next直到末尾的长度会 <=
    // head到slow的长度(看链表长度是奇数还是偶数了)
    auto slow = head, fast = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    // 反转较短的链表
    auto p = reverseList(slow->next);

    // 判断一下是否回文
    while (p) {
      if (p->val != head->val) {
        return false;
      }

      p = p->next, head = head->next;
    }

    return true;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *p = NULL;
    while (head) {
      auto ne = head->next;
      head->next = p;

      p = head, head = ne;
    }

    return p;
  }
};