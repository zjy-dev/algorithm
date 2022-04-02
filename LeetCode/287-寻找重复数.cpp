#include "LeetCode.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 将i -> nums[i]不断的串成一个静态链表
        // 而对于重复的tar, 总有两条边指向他
        // 也就是链表一定有环
        // 此时我们要找的tar就是入环点
        // 利用环形链表2的知识即可
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int p = 0;
        while (p != slow) {
            p = nums[p];
            slow = nums[slow];
        }

        return p;
    }
};