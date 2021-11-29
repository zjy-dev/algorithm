#include"LeetCode.h"

class Solution{
public:
    bool isSymbol(const string& s)
    {
        return s == "+" or s == "-" or s == "*" or s == "/";
    }

    int calculate(int a, int b, const string& s)
    {
        if(s == "+")
            return a + b;
        else if(s == "-")
            return a - b;
        else if(s == "*")
            return a * b;
        else
            return a / b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(const auto& s : tokens)
        {
            if(isSymbol(s))
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                stk.push(calculate(b, a, s));
            }
            else
                stk.push(atoi(s.c_str()));
        }

        return stk.top();
    }
};