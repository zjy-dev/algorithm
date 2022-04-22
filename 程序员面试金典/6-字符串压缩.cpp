#include "LeetCode.h"

class Solution {
public:
    string compressString(string s) {
        string ans("");
        int n(s.size()), i(0);
        while (i < n) {
            char c(s[i]);
            int cnt(0);

            while (i < n && s[i] == c) {
                cnt++, i++;
            }

            ans += c + to_string(cnt);
            if (ans.size() >= n) {
                return s;
            }
        }

        return ans;
    }
};