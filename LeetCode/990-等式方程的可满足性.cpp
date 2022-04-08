#include "LeetCode.h"

class Solution {
public:
    // 并查集
    int f[26];

    void unionLetter(int a, int b) {
        f[find(a)] = find(b);
    }

    int find(int a) {
        if (f[a] != a) {
            f[a] = find(f[a]);
        }

        return f[a];
    }

    bool equationsPossible(vector<string>& equations) {

        // 初始化并查集
        for (int i = 0; i < 26; i++) {
            f[i] = i;
        }

        // 先将相等的字母都union起来
        for (const auto& val : equations) {
            int a = val[0] - 'a', b = val[3] - 'a';
            if (val[1] == '=') {
                unionLetter(a, b);
            }
        }

        // 再判断不等的字母是否在同一个组里
        for (const auto& val : equations) {
            int a = val[0] - 'a', b = val[3] - 'a';
            if (val[1] == '!') {
                if (find(a) == find(b)) {
                    return false;
                }
            }
        }

        return true;
    }
};