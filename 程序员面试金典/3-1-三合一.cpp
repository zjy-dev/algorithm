#include "LeetCode.h"

class TripleInOne {
public:
  // 把一个数组当成三个用, 用stkSize * stkNo当做基地址,
  // p[stkNo]当做偏移量就可以了
  vector<int> v;
  int stkSize;

  int p[3];

  TripleInOne(int stackSize) {
    this->stkSize = stackSize;
    v.resize(stackSize * 3);
    memset(p, 0, sizeof p);
  }

  void push(int no, int value) {
    if (p[no] == stkSize) {
      return;
    }

    v[stkSize * no + p[no]++] = value;
  }

  int pop(int no) {
    if (p[no] == 0) {
      return -1;
    }
    return v[stkSize * no + --p[no]];
  }

  int peek(int no) {
    if (p[no] == 0) {
      return -1;
    }

    return v[stkSize * no + p[no] - 1];
  }

  bool isEmpty(int no) { return p[no] == 0; }
};