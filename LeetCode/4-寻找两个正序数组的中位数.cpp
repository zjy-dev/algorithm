#include"LeetCode.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int n = ((len1 + len2) >> 1) + 1;
        
        int slow = 0, fast = 0;
        for(int i = 0, j = 0; n; n--)
        {
            slow = fast;
            if(i >= len1)
            {
                fast = nums2[j++];
                continue;
            }
            if(j >= len2)
            {
                fast = nums1[i++];
                continue;
            }
            fast = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        }

        if(len1 + len2 & 1)
            return fast;
        
        return double(fast + slow) / 2.0;
    }
};
