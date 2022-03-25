#include"LeetCode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> hash;
        int n = s.size();
        int ans = 0;

        for (int slow = 0, fast = 0; fast < n; fast++) {
            // 假设要以fast结尾, 那么hash(fast)必须是false才可以
            while (hash[s[fast]] == true) {
                hash[s[slow]] = false;
                slow++;
            }

            // 现在可以以fast结尾了
            hash[s[fast]] = true;
            
            // 更新答案
            ans = max(ans, fast - slow + 1);
        }

        return ans;
    }
};