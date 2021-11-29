#include"LeetCode.h"

const string Hash = "12210111011122000010020202";

class Solution{
public:
    string toLower(string str) 
    {
        for (auto& c : str)
            c = tolower(c);
        
        return str;
    }
    vector<string> findWords(vector<string>& words) 
    {
        vector<string> ans;
        for(auto &s : words)
        {
            auto temp = toLower(s);
            char idx = Hash[temp[0] - 'a'];
            bool ok = true;
            for(const auto& c : temp)
                if(Hash[c - 'a'] != idx)
                {
                    ok = false;
                    break;
                }
            if(ok)
                ans.push_back(s);
        }

        return ans;
    }
};