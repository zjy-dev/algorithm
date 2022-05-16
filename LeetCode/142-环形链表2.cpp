#include "LeetCode.h"

class Solution {
public:
  // 快指针每次走两步, 慢指针每次走一步
  // 快慢指针一定会在慢指针入环的第一圈相遇(每步快慢指针距离-1,
  // 第一圈肯定追上了) 假设非环的部分长度为a, 快慢指针相遇的点是在入环点后b步,
  // 而环长度为b + c 则慢指针走了 a + b, 快指针走了 2a + 2b 或 a + b + n(b + c),
  // 其中n的意思是在环内走了n圈 则a + b = nb + nc, 整理得 a = (n - 1)(b + c) + c
  // 此时我们让p从头开始走, 和慢指针同步移动
  // 则走a步后, p到达入环点, 慢指针走了a + b + c + (n - 1)(b + c) 即 a + n(b +
  // c) 也就是说, p和慢指针在入环点相遇

  ListNode *detectCycle(ListNode *head) {
    auto fast = head, slow = head;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next, fast = fast->next->next;

      if (slow == fast) {
        auto p = head;
        while (p != slow) {
          slow = slow->next;
          p = p->next;
        }

        return p;
      }
    }

    return NULL;
  }
};