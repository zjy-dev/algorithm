#include "LeetCode.h"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // 在l1上直接相加, 不消耗额外内存
    ListNode *ans = l1;

    while (l1->next != NULL && l2->next != NULL) {
      l1->val += l2->val;

      // 处理进位
      l1->next->val += l1->val / 10;
      l1->val %= 10;

      l1 = l1->next, l2 = l2->next;
    }

    // 很重要
    l1->val += l2->val;

    // 如果l2长, 就把剩下的部分拼接到l1后面
    if (l1->next == NULL) {
      l1->next = l2->next;
    }

    // 处理进位
    while (l1->next != NULL) {
      l1->next->val += l1->val / 10;
      l1->val %= 10;

      l1 = l1->next;
    }

    // 处理溢出
    while (l1->val >= 10) {
      l1->next = new ListNode(l1->val / 10);
      l1->val %= 10;

      l1 = l1->next;
    }

    // 返回答案
    return ans;
  }
};