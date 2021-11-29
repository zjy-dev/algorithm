#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        int l = newInterval[0], r = newInterval[1];
        bool flag = false;
        for(int i = 0; i < intervals.size(); i++)
            if(intervals[i][1] < l)
                ans.push_back(intervals[i]);
            else if(intervals[i][0] > r)
            {
                if(!flag)
                    flag = true, ans.push_back({l, r});
                ans.push_back(intervals[i]);
            }
            else
                l = min(l, intervals[i][0]), r = max(r, intervals[i][1]);
        
        if(!flag)
            ans.push_back({l, r});
        return ans;
    }
};