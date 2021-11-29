#include"LeetCode.h"

class Solution{
public:
    int mergeSort(vector<int>& nums, int l, int r)
    {
        if(l >= r)
            return 0;
        auto mid = (l + r) >> 1;
        auto ans = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, r);
        vector<int> temp(r - l + 1);
        int i = l, j = mid + 1, k = 0;
        while(i <= mid and j <= r)
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++], ans += (mid - i + 1);
        while(i <= mid)
            temp[k++] = nums[i++];
        while(j <= r)
            temp[k++] = nums[j++];
        copy(temp.begin(), temp.end(), nums.begin() + l);

        return ans;
    }
    
    int reversePairs(vector<int>& nums) 
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};