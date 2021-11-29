#include"LeetCode.h"

class Solution {
public:
    bool isNumber(string s) 
    {
        if(!s.size())
            return false;
        int idx = 0;

        while(s[idx] == ' ')
            idx++;
        
        bool flag = readInt(s, idx);

        if(s[idx] == '.')
        {
            idx++;
            flag = readUInt(s, idx) or flag;
        }

        if(s[idx] == 'e' or s[idx] == 'E')
        {
            idx++;
            flag = readInt(s, idx) and flag;
        }

        while(s[idx] == ' ')
            idx++;
        
        return flag && idx == s.size();
    }

    bool readInt(const string& s, int& idx)
    {
        if(s[idx] == '+' or s[idx] == '-')
            idx++;
        return readUInt(s, idx);
    }

    bool readUInt(const string& s, int& idx)
    {
        int flag = idx;
        while(s[idx] >= '0' and s[idx] <= '9') 
            idx++; 
        
        return idx > flag;
    }

};




