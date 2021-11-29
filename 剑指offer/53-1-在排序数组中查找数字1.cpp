#include"LeetCode.h"

class Solution{
public:
    int search(vector<int>& nums, int val) 
    {
        int n = nums.size();
        if(!n)
            return 0;
        int subL;
        int l = 0, r = n - 1, mid;
        while(l < r)
            if(nums[mid = (l + r) >> 1] >= val)
                r = mid;
            else
                l = mid + 1;
        
        if(nums[l] != val)
            return 0;
        subL = l;

        l = 0, r = n - 1;
        while(l < r)
            if(nums[mid = (l + r + 1) >> 1] > val)
                r = mid - 1;
            else
                l = mid;
        

        return l - subL + 1;
    }
};