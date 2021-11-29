#include"LeetCode.h"

class Solution {
public:
    vector<int> printNumbers(int n) 
    {
        vector<int> ans;
        n = pow(10, n);
        for(int i = 1; i < n; i++)
            ans.push_back(i);
        
        return ans;
    }
};