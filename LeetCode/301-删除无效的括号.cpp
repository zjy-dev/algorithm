#include "LeetCode.h"

class Solution {
public:
    int maxPair, n;
    unordered_set<string> ans;
    string s;

    int len = 0;
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        this->n = s.size();

        // 统计左右括号数量
        int l = 0, r = 0;
        for (const auto& c : s) {
            if (c == '(') {
                l++;
            } else if (c == ')' && l > r) { // 左括号必须多, 右括号才有效
                r++;
            }
        }

        // 最多能出现的括号对数也就是r
        this->maxPair = r;

        dfs("", 0, 0);

        vector<string> v;
        for (const auto& str : ans) {
            v.push_back(str);
        }

        return v;
    }

    // cur代表生成的字符串, pos代表搜到s的pos了
    // cnt的话, 搜到左括号 + 1, 搜到右括号 - 1
    // 因此任何时刻cnt必须有: 0 < cnt <= maxPair
    void dfs(string cur, int pos, int cnt) {
        // 剪枝
        if (cnt < 0 || cnt > maxPair) {
            return;
        }

        // dfs终点
        if (pos == this->n) {
            // cnt必须为0, 且cur的长度必须大于等于len才可能最优
            if (cnt == 0 && cur.size() >= this->len) {
                // 如果大于len, 那么之前的全部作废
                if (cur.size() > this->len) {
                    this->len = cur.size();
                    ans.clear();
                }
                ans.insert(cur);
            }
    
            return;
        }

        // dfs, 枚举选和不选
        if (s[pos] == '(') {
            dfs(cur, pos + 1, cnt);
            dfs(cur + '(', pos + 1, cnt + 1);
        } else if (s[pos] == ')') {
            dfs(cur, pos + 1, cnt);
            dfs(cur + ')', pos + 1, cnt - 1);
        } else { // 当然, 不是括号必须得选
            dfs(cur + s[pos], pos + 1, cnt);
        }
    }
};