#include"LeetCode.h"

/**
 * 时间复杂度 -> O(logn), 二分 
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
    int minArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;

        // 在脑海中或纸上绘制一下直角坐标系的图像
        while (l < r) {
            // 如果中值小于右端点值, 说明min在中值或中值的左侧
            if (nums[mid = (l + r) >> 1] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) { // 如果中值大于右端点值, 则在右侧, 且中值不是最小值
                l = mid + 1;
            } else { // 如果中值和右端点值相等, 可能左可能右, 只能断定右端点不被需要(可以被中值代替)
                r--;
            }
        }

        return nums[l];
    }
};

/**
 * 1.xxx
 * 2.xxx
 */