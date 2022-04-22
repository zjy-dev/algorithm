#include "LeetCode.h"

class Solution {
public:
    // len是真实长度
    string replaceSpaces(string s, int len) {
        int n = s.size();
        int p = n - 1;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                s[p--] = '0';
                s[p--] = '2';
                s[p--] = '%';
            } else {
                s[p--] = s[i];
            }
        }

        return s.substr(p + 1);
    }
};