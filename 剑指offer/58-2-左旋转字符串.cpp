#include"LeetCode.h"

class Solution{
public:
    string reverseLeftWords(string s, int n)
    {
        return s.substr(n, INT_MAX) + s.substr(0, n);
    }
};