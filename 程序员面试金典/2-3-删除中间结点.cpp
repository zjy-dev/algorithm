#include "LeetCode.h"

class Solution {
public:
  void deleteNode(ListNode *node) {
    // 无法自己删除自己
    // 因此考虑删除后一个结点
    // 当然, 要将后一个结点的值拷贝到自己身上一份

    // 1.将后一个结点的值拷贝到自己身上
    node->val = node->next->val;

    // 2.删除后一个结点
    node->next = node->next->next;
  }
};