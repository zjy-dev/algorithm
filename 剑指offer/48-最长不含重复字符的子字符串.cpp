#include"LeetCode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, bool> hash;
        int n = s.size(), ans = 0;
        for(int i = 0, j = 0; j < n; j++)
        {
            while(hash[s[j]])
                hash[s[i++]] = false;
            hash[s[j]] = true;
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};