#include"LeetCode.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        if(!k)
            return {};
        quick_select(arr, 0, arr.size() - 1, k);
        vector<int> ans(k);
        for(int i = 0; i < k; i++)
            ans[i] = arr[i];
        return ans;
    }

    void quick_select(vector<int>& arr, int l, int r, int k)
    {
        if(l == r)
            return;
        int i = l - 1, j = r + 1, flag = arr[(l + r) >> 1];
        while (i < j)
        {
            while(arr[++i] < flag);
            while(arr[--j] > flag);
            if(i < j)
                swap(arr[i], arr[j]);
        }
        int subL = j - l + 1;
        
        if(subL == k)
            return;
        else if(subL > k)
            quick_select(arr, l, j, k);
        else
            quick_select(arr, j + 1, r, k - subL);
    }
};