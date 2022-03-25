#include "LeetCode.h"

unordered_map<char, string> table {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        // 用深度优先搜索解决全排列
        dfs(digits, 0, "");

        return ans;
    }

    void dfs(const string& digits, int idx, string temp) {
        if (idx == digits.size()) {
            ans.push_back(temp);
        }

        // 全排列
        for (const char& c : table[digits[idx]]) {
            dfs(digits, idx + 1, temp + c);
        }
    }
};