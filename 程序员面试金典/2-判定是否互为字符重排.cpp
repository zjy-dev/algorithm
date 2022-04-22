#include "LeetCode.h"

class Solution {
public:
    // 简单题
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        unordered_map<char, int> hash;
        for (const auto& c : s1) {
            hash[c]++;
        }

        for (const auto& c : s2) {
            hash[c]--;
        }

        for (const auto& p : hash) {
            if (p.second != 0) {
                return false;
            }
        }

        return true;
    }
};