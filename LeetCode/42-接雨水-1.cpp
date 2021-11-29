#include"LeetCode.h"

class Solution{
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0;
        while(l < r)
        {
            l_max = max(height[l], l_max), r_max = max(height[r], r_max);
            if(l_max < r_max)
                ans += l_max - height[l++];
            else
                ans += r_max - height[r--];
        }

        return ans;
    }
};