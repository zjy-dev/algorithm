#include"LeetCode.h"

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.size();
        for(int j = n - 1, i; ; )
        {
            while(j >= 0 and s[j] == ' ')
                j--;
            i = j;
            while(i >= 0 and s[i] != ' ')  
                i--;
            return j - i;
        }
        return 0;
    }
};