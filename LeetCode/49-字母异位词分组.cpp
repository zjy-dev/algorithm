#include"LeetCode.h"

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(string& s : strs)
        {
            auto t = s;
            sort(t.begin(), t.end());
            hash[t].push_back(s);
        }

        vector<vector<string>> ans;
        for(const auto& t : hash)
            ans.push_back(t.second);
        
        return ans;
    }
};