#include "LeetCode.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> hash{
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (const char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty() == true || stk.top() != hash[c]) {
                    return false;
                }

                stk.pop();
            }
        }

        return stk.empty() == true;
    }   
};