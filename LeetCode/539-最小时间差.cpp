#include"LeetCode.h"

class Solution{
public:
    bool hash[1440];
    int findMinDifference(vector<string>& timePoints) {
        int ans = INT_MAX;
        for(const auto& s : timePoints)
        {
            auto t = str2num(s);
            if(hash[t])
                return 0;
            hash[t] = true;
        }
        
        int first = 0, last = 1439;

        while(!hash[first])
            first++;
        while(!hash[last])
            last--;

        int pre = first;
        for(int i = first + 1; i <= last; i++) 
            if(hash[i])
                ans = min(ans, i - pre), pre = i;
        
        return min(ans, 1440 - (last - first));
    }
    int str2num(const string& s)
    {
        int h = s[1] - '0' + (s[0] - '0') * 10;
        int m = s[4] - '0' + (s[3] - '0') * 10;
        return 60 * h + m;
    }
};