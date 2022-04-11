#include "LeetCode.h"

class Solution {
public: 
    vector<string> ans;
    vector<bool> vis;
    string temp;
    int n;
    vector<string> permutation(string s) {
        if (s.size() == 0) {
            return {};
        }

        this->n = s.size();
        vis.resize(n, false);
        sort(s.begin(), s.end());

        dfs(0, s);

        return ans;
    }

    void dfs(int idx, const string &s) {
        if (idx == n) {
            ans.push_back(temp);
        }

        for (int i = 0; i < n; i++) {
            // !vis[i - 1]是因为:
            // 如果前面重复的字符已经填过了, 那么即使重复也可以继续填
            // 例如有5个s, 我们称其为1-5号s
            // 只有1号s填过了, 才能填2号, 然后才能填3号...
            // 保证5个s只会以一种顺序出现
            if (vis[i] == true || (i > 0 && s[i] == s[i - 1] && !vis[i - 1])) {
                continue;
            }

            temp.push_back(s[i]);
            vis[i] = true;
            dfs(idx + 1, s);
            vis[i] = false;
            temp.pop_back();
        }
    }
};