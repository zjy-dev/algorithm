#include "LeetCode.h"

class Solution {
public:
    bool isUnique(string str) {
        unordered_set<char> vis;

        for (const auto& c : str) {
            if (vis.count(c)) {
                return false;
            }

            vis.insert(c);
        }

        return true;
    }
};