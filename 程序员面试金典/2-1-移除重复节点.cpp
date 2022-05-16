#include "LeetCode.h"

class Solution {
public:
  // 未排序则需要哈希表
  unordered_set<int> s;

  ListNode *removeDuplicateNodes(ListNode *head) {
    if (head == NULL) {
      return NULL;
    }

    auto p = head;
    while (p && p->next) {
      s.insert(p->val);
      if (s.count(p->next->val)) {
        p->next = p->next->next;
        continue;
      }

      p = p->next;
    }

    return head;
  }
};