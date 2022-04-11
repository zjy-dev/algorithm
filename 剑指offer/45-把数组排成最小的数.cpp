#include"LeetCode.h"

class Solution {
public:
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> v;

        for (int i = 0; i < n; i++) {
            v.push_back(to_string(nums[i]));
        }

        // 贪心, 使最终的排列方式中, 对任何前面的数s1和后面的数s2, 满足s1 + s2 < s2 + s1
        sort(v.begin(), v.end(), [](const string& s1, const string& s2) {
            return s1 + s2 < s2 + s1;
        });

        string ans = "";
        for (const auto& str : v) {
            ans += str;
        }

        return ans;
    }
};