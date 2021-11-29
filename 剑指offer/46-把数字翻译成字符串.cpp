#include"LeetCode.h"

class Solution {
public:
    int translateNum(int num) 
    {
        auto str = to_string(num);
        int n = str.size(), ans = 1, p = 1, q = 1;
        for(int i = 1; i < n; i++)
        {
            ans = q;
            string temp = str.substr(i - 1, 2);
            if(temp >= "10" and temp <= "25")
                ans += p;
            
            p = q, q = ans;
        }

        return ans;
    }
};