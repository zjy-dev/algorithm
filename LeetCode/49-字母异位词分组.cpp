#include"LeetCode.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) {
            return {};
        }
        
        // 以str排序的结果作为key, 将字母异位词聚合在一起
        unordered_map<string, vector<string>> hash;

        for (auto& str : strs) {
            auto t = str;
            sort(t.begin(), t.end());

            hash[t].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto& p : hash) {
            ans.push_back(p.second);
        }

        return ans;
    }
};