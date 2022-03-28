#include "LeetCode.h"

class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int n = nums.size();

        if (n == 0) {
            return -1;
        }

        if (n == 1) {
            return nums[0] == tar ? 0 : -1;
        }

        // 二分
        int l = 0, r = n - 1, mid;

        while (l < r) {
            if (nums[mid = (l + r) >> 1] == tar) {
                return mid;
            }

            // 每次二分后, 必然有一半有序, 一半可能有序可能乱序
            
            if (nums[l] <= nums[mid]) { // 如果左边有序, 就在左边二分
                if (tar >= nums[l] && tar <= nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else { // 否则就是右边有序
                if (tar >= nums[mid] && tar <= nums[r]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
        }

        return nums[l] == tar ? l : -1;
    }
};