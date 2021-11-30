#include"LeetCode.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) 
    {
        int n = s.size();
        if(!n)
            return false;
        
        //dp[i]表示s[0 ~ i]可以满足题目条件
        vector<bool> dp(n);
        unordered_set<string> hash;
        for(const auto& s : dict)
            hash.insert(s);

        //边界
        dp[0] = hash.count(s.substr(0, 1));

        for(int i = 1; i < n; i++)
            for(int j = -1; j < i; j++)//对每一个从头开始的子串, 对每一个位置进行分隔, 尽可能让它满足题目条件
            {
                dp[i] = (j == -1 ? true : dp[j]) and hash.count(s.substr(j + 1, i - j));
                if(dp[i])
                    break;
            }
        
        return dp[n - 1];
    }
};  