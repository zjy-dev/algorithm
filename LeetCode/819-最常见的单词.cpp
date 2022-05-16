#include "LeetCode.h"

class Solution {
public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    unordered_set<string> bannedHash;
    for (const auto &s : banned) {
      bannedHash.insert(s);
    }

    for (auto &c : paragraph) {
      if (isalpha(c)) {
        c = tolower(c);
      }
    }

    unordered_map<string, int> hash;

    int n = paragraph.size();
    int i = 0, j;

    while (true) {
      // 循环结束时p[i]是字母, 如果i走到头了就break
      while (i < n && isalpha(paragraph[i]) == false) {
        i++;
      }
      if (i >= n) {
        break;
      }

      // 循环结束时p[j]刚好不是字母或j = n
      j = i + 1;
      while (j < n && isalpha(paragraph[j])) {
        j++;
      }

      // 提取字符串
      string t = paragraph.substr(i, j - i);

      // 判断是否被禁用了, 被禁用直接continue
      if (bannedHash.count(t)) {
        i = j;
        continue;
      }

      hash[t]++;
      i = j;
    }

    // 寻找ans
    string ans;
    int cnt = 0;
    for (const auto &p : hash) {
      if (p.second > cnt) {
        cnt = p.second;
        ans = p.first;
      }
    }

    return ans;
  }
};