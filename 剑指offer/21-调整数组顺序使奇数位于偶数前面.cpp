#include"LeetCode.h"

/**
 * 时间复杂度 -> O(n), 快慢双指针
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        
        // [0, slow)全是奇数, 这是因为每次slow++都伴随着奇数被交换过来
        // [slow, fast)区间全是偶数, 这是因为fast指针只遇上了slow个奇数, 都放在[0, slow)了
        int fast = 0, slow = 0;

        while (fast < n) {
            // 遇到奇数了, 就把他和slow上的偶数交换, slow后移
            if (nums[fast] & 1) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }

        return nums;
    }
};