#include"LeetCode.h"

class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        for(const auto& c : s)
            if(c == ' ')
                cnt++;  
        
        int n = cnt * 2 + s.size();
        string ans(n, 0);
        int i = 0;
        for(const auto& c : s)
            if(c != ' ')
                ans[i++] = c;
            else
                ans[i++] = '%', ans[i++] = '2', ans[i++] = '0';

        return ans;
    }
};