#include "LeetCode.h"

class Solution {
public:
  // 防止重复复制, 要标记每一个旧结点是否被复制过
  unordered_map<Node *, Node *> hash;

  Node *copyRandomList(Node *head) {
    if (head == NULL) {
      return NULL;
    }

    return dfs(head);
  }

  // 复制一个以head为头的复杂链表, 并返回新链表的头指针
  Node *dfs(Node *head) {
    if (head == NULL) {
      return NULL;
    }
    // 不能重复复制
    if (hash[head] != NULL) {
      return hash[head];
    }

    // 复制头结点
    auto newHead = new Node(head->val);

    // 一定要在这里存入哈希表
    // 以防止接下来的dfs再次搜到head, 造成重复复制， 然后无限递归至栈溢出
    hash[head] = newHead;

    // 递归复制head的next和random, 并和newHead接起来
    newHead->next = dfs(head->next);
    newHead->random = dfs(head->random);

    return newHead;
  }
};

// 不用管, 官方提供的数据结构
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};