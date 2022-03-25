#include"LeetCode.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n - 1, mid;

        // 二分只能查出[0, n - 1]的值, 对n要特判
        if (nums[r] == r) {
            return r + 1;
        }

        while (l < r) {
            // 如果nums[mid] != mid, 说明左边或mid少数了
            if (nums[mid = (l + r) >> 1] != mid) {
                r = mid;
            } else { // 否则说明少的数在右边
                l = mid + 1;
            }
        }

        return l;
    }
};