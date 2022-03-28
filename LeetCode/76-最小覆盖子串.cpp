#include "LeetCode.h"

class Solution {
public:
    string minWindow(string s, string t) {
        // 维护t中的某字符还差几个才够覆盖t
        unordered_map<char, int> hash;

        // 维护剩余t中多少个字符未覆盖
        int cnt = t.size();

        int n = s.size();

        // 初始化哈希表
        for (const auto& c : t) {
            hash[c]++;
        }

        // 快慢双指针, 每次强制以fast结尾去覆盖t
        int len = INT_MAX, st;
        for (int slow = 0, fast = 0; fast < n; fast++) {
            if (hash[s[fast]] > 0) {
                cnt--;
            }
            hash[s[fast]]--;

            // cnt == 0说明覆盖掉了
            if (cnt == 0) {
                // 也许还能缩小范围, 尽可能尝试一下
                while (hash[s[slow]] < 0) {
                    hash[s[slow++]]++;
                }

                // 尝试更新答案
                if (fast - slow + 1 < len) {
                    len = fast - slow + 1;
                    st = slow;
                }
            }
        }

        if (len == INT_MAX) {
            return "";
        }
        return s.substr(st, len);
    }
};