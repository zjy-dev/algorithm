#include "LeetCode.h"

class Trie {
public:
  // 递归的数据结构
  Trie *next[26];
  bool isEnd;

  Trie() {
    memset(next, 0, sizeof next);
    isEnd = false;
  }

  void insert(string word) {
    Trie *p = this;
    for (const auto &c : word) {
      if (p->next[c - 'a'] == NULL) {
        p->next[c - 'a'] = new Trie();
      }
      p = p->next[c - 'a'];
    }

    p->isEnd = true;
  }

  bool search(string word) {
    Trie *p = this;
    for (const auto &c : word) {
      if (p->next[c - 'a'] == NULL) {
        return false;
      }
      p = p->next[c - 'a'];
    }

    return p->isEnd;
  }

  bool startsWith(string prefix) {
    Trie *p = this;
    for (const auto &c : prefix) {
      if (p->next[c - 'a'] == NULL) {
        return false;
      }
      p = p->next[c - 'a'];
    }

    return true;
  }
};
