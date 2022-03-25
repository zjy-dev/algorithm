#include"LeetCode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, bool> hash;
        int ans = 0;

        for (int slow = 0, fast = 0; fast < n; fast++) {
            // 对于每一次循环, 都强制使得其以fast结尾

            // 为了以fast结尾, s[fast]不能出现过
            while (hash[s[fast]] == true) {
                hash[s[slow]] = false;
                slow++;
            }

            // 现在可以以fast结尾了
            hash[s[fast]] = true;

            ans = max(ans, fast - slow + 1);
        }

        return ans;
    }
};