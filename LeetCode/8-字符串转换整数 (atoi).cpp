#include"LeetCode.h"

class Solution {
public:
    pair<bool, string> getStr(string s)
    {
        bool isNeg = false;
        int n = s.size(), i = 0;
        while(s[i++] == ' ');
        if(s[i++] == '-')
            isNeg = true;
        int st = i;
        while(s[i] <= '9' and s[i] >= '0')
            i++;
        auto len = i - st;
        return {isNeg, s.substr(st, len)};
    }

    int myAtoi(string s) {
        bool isNeg;
        tie(isNeg, s) = getStr(s);
        long long ans = 0;
        for(const auto& c : s)
        {
            auto t = ans * 10 + c - '0';
            if(isNeg and t > -(long long)INT_MIN)
                return -ans;
            else if(!isNeg and t > INT_MAX)
                return ans;
        }

        return isNeg? -ans : ans;
    }
};


