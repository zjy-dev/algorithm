#include "LeetCode.h"

class Solution {
public:
  int getLen(ListNode *h) {
    int ans = 0;
    while (h) {
      h = h->next;
      ans++;
    }

    return ans;
  }

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = getLen(headA), lenB = getLen(headB);

    // 断言A短
    if (lenA > lenB) {
      swap(lenA, lenB);
      swap(headA, headB);
    }

    for (int i = lenB - lenA; i > 0; i--) {
      headB = headB->next;
    }

    while (headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }

    return headA;
  }
};