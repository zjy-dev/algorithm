#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        for(const auto& interval : intervals)
        {
            if(interval[0] > r)
                ans.push_back({l, r}), l = interval[0];
            r = max(r, interval[1]);
        }
        ans.push_back({l, r});
        return ans;
    }
};  