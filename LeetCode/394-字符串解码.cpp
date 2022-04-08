#include "LeetCode.h"

class Solution {
public:
    // 从s中获取一个数字, p传引用方便更新
    string getDigit(const string& s, int& p) {
        string ans = "";

        while (isdigit(s[p])) {
            ans += s[p];
            p++;
        }

        return ans;
    }
    
    // 可有可无, 主要不想主方法太长
    string toString(vector<string>& v) {
        string ans = "";
        for (const auto& val : v) {
            ans += val;
        }

        return ans;
    }


    string decodeString(string s) {
        int n = s.size();
        int p = 0;

        // 栈
        vector<string> stk;


        while (p < n) {
            if (isdigit(s[p])) { // 数字入栈
                stk.push_back(getDigit(s, p));
            } else if (isalpha(s[p]) || s[p] == '[') { // 字母或左括号入栈
                stk.push_back(string(1, s[p++]));
            } else { // ']', 右括号出栈
                // 出栈括号内的字符串, 存入val
                string val = "";
                while (stk.back() != "[") {
                    val = stk.back() + val;
                    stk.pop_back();
                }

                // 左括号出栈
                stk.pop_back();

                // 数字出栈
                int num = stoi(stk.back());
                stk.pop_back();

                // 将val重复num次存入stk
                string str;
                while (num--) {
                    str += val;
                }
                stk.push_back(str);

                // 更新指针
                p++;
            }
        }

        return toString(stk);
    }
};