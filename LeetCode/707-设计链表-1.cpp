#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *next;
  int val;
};

class MyLinkedList {
private:
  Node *head;

public:
  MyLinkedList() { this->head = new Node({NULL, 0}); }

  int get(int index) {
    if (index < 0)
      return -1;
    auto p = this->head;

    while (index-- >= 0) {
      p = p->next;
      if (!p)
        return -1;
    }

    return p->val;
  }

  void addAtHead(int val) { head->next = new Node({head->next, val}); }

  void addAtTail(int val) {
    auto p = this->head;

    while (p->next)
      p = p->next;

    p->next = new Node({NULL, val});
  }

  void addAtIndex(int index, int val) {
    if (index < 0)
      return;
    auto p = this->head;

    while (index--) {
      p = p->next;
      if (!p)
        return;
    }

    p->next = new Node({p->next, val});
  }

  void deleteAtIndex(int index) {
    if (index < 0)
      return;
    auto p = this->head;

    while (index--) {
      p = p->next;
      if (!p->next)
        return;
    }

    p->next = p->next->next;
  }
};