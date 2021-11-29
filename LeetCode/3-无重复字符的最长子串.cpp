#include"LeetCode.h"

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char, int> hash;

        for(int i = 0, j = 0; j < n; j++)
        {
            hash[s[j]]++;
            while(hash[s[j]] > 1)
                hash[s[i++]]--;
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};