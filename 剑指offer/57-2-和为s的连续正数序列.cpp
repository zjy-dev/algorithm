#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int tar) 
    {
        vector<vector<int>> ans;
        int s = 0;
        for(int i = 1, j = 0; i + j <= tar; )
        {
            if(s < tar)
                s += ++j;
            else if(s > tar)
                s -= i++;
            else
            {
                vector<int> v;
                for(int t = i; t <= j; t++)
                    v.push_back(t);
                ans.push_back(v);
                s -= i++, s += ++j;
            }
        }

        return ans;
    }
};