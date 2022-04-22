#include "LeetCode.h"

class Solution {
public:
    unordered_set<char> wordSet{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    string toGoatLatin(string s) {
        string ans;

        int n = s.size(), i = 0, cnt = 1;
        while (i < n) {
            int st = i;
            while (i < n && s[i] != ' ') {
                i++;
            }

            // [st, i)是该单词
            if (wordSet.count(s[st])) {
                ans += s.substr(st, i - st);
            } else {
                ans += s.substr(st + 1, i - st - 1) + s[st];
            }

            ans += "ma" + string(cnt, 'a') + " ";

            // 跳过空格, 更新索引
            i++, cnt++;
        }

        return ans.substr(0, ans.size() - 1);
    }
};