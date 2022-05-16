#include "LeetCode.h"

class Solution {
public:
  bool isFlipedString(string s1, string s2) {
    // 转换成kmp, O(n)
    // 这是因为s1 + s1里包含了所有旋转后可能的结果
    return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;
  }
};