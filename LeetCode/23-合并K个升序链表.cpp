#include "LeetCode.h"

struct Node {
  ListNode *p;
  bool operator<(const Node &obj) const { return p->val > obj.p->val; }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // 使用堆, 并自定义排序规则, 形成一个小根堆
    // 每次取val最小的list串起来, 然后将该list后移即可
    priority_queue<Node> heap;

    auto ans = new ListNode();
    auto p = ans;

    for (const auto &l : lists) {
      if (l != NULL) {
        heap.push({l});
      }
    }

    while (heap.empty() == false) {
      auto t = heap.top().p;
      heap.pop();

      // 串起来
      p->next = t;
      p = p->next;

      if (t->next != NULL) {
        heap.push({t->next});
      }
    }

    return ans->next;
  }
};