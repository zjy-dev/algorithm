#include"LeetCode.h"

class Solution {
public:
    string minNumber(vector<int>& nums) 
    {
        string ans;
        vector<string> strs(nums.size());
        for(int i = 0; i < nums.size(); i++)
            strs[i] = to_string(nums[i]);
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2){
            return s1 + s2 < s2 + s1;
        });
        
        for(const auto& str : strs)
            ans += str;
        
        return ans;
    }
};