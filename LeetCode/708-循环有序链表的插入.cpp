#include "LeetCode.h"

class Solution {
public:
  Node *insert(Node *head, int val) {
    auto p = new Node(val, NULL);
    if (!head)
      head = p, head->next = head;
    else if (head->next == head) {
      head->next = p;
      p->next = head;
    } else
      insertNode(head, p);

    return head;
  }

  void insertNode(Node *head, Node *node) {
    int val = node->val;
    auto p = head, biggest = head;
    bool flag = 1;
    for (; flag or p != head; p = p->next) {
      if (p->val >= biggest->val)
        biggest = p;
      if (p->val <= val and p->next->val >= val) {
        node->next = p->next, p->next = node;
        return;
      }
      flag = false;
    }

    node->next = biggest->next, biggest->next = node;
  }
};
