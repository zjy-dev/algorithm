#include"LeetCode.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        if(!k)
            return {};
        priority_queue<int> heap;

        int i = 0;
        for(; i < k; i++)
            heap.push(arr[i]);
        for(; i < arr.size(); i++)
            if(arr[i] < heap.top())
                heap.pop(), heap.push(arr[i]);
        vector<int> ans(k);
        for(int i = 0; i < k; i++)
            ans[i] = heap.top(), heap.pop();
        
        return ans;
    }
};