#include"LeetCode.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) 
    {
        bool r = false, c = false;
        int m = nums.size(), n = nums[0].size();

        for(int i = 0; i < n; i++)
            if(!nums[0][i])
            {
                r = true;
                break;
            }

        for(int i = 0; i < m; i++)
            if(!nums[i][0])
            {
                c = true;
                break;
            }
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(!nums[i][j])
                    nums[i][0] = 0, nums[0][j] = 0;

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(!nums[i][0] or !nums[0][j])
                    nums[i][j] = 0;
        
        if(r)
            for(int i = 0; i < n; i++)
                nums[0][i] = 0;

        if(c)
            for(int i = 0; i < m; i++)
                nums[i][0] = 0; 
    }
};

    