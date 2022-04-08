#include "LeetCode.h"

// 不滚动数组
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // 寻找一个总和为sum >> 1的选取方案即可, 令tar = sum >> 1
        int tar = 0;
        for (int i = 0; i < n; i++) {
            tar += nums[i];
        }

        // 总和为奇数, 直接返回false
        if (tar & 1) {
            return false;
        }
        
        // 总和为偶数, 则将tar >> 1
        tar >>= 1;

        // dp[i][j]表示[0..i]中能否有一种方案, 恰好能够选出总和为j
        vector<vector<bool>> dp(n, vector<bool>(tar + 1, false));

        // dp边界
        dp[0][0] = true; // 肯定能恰好填满容量为0的背包
        if (nums[0] <= tar) { // 也能恰好填满容量为nums[0]的背包
            dp[0][nums[0]] = true;
        }

        // 剪枝
        if (dp[0][tar] == true) {
            return true;
        }

        // dp
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= tar; j++) {
                // 不选i
                dp[i][j] = dp[i - 1][j];

                // 选i
                if (nums[i] <= j) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i]];
                }
            }

            // 剪枝, 一种方案成立就直接返回了
            if (dp[i][tar] == true) {
                return true;
            }
        }

        return false;
    }
};

// 滚动数组
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // 寻找一个总和为sum >> 1的选取方案即可, 令tar = sum >> 1
        int tar = 0;
        for (int i = 0; i < n; i++) {
            tar += nums[i];
        }

        // 总和为奇数, 直接返回false
        if (tar & 1) {
            return false;
        }
        
        // 总和为偶数, 则将tar >> 1
        tar >>= 1;

        // dp[i][j]表示[0..i]中能否有一种方案, 恰好能够选出总和为j
        vector<bool> dp(tar + 1, false);

        // dp边界
        dp[0] = true; // 肯定能恰好填满容量为0的背包
        if (nums[0] <= tar) { // 也能恰好填满容量为nums[0]的背包
            dp[nums[0]] = true;
        }

        // 剪枝
        if (dp[tar] == true) {
            return true;
        }

        // dp
        for (int i = 1; i < n; i++) {
            // 反向滚动, 为了不读到脏数据
            for (int j = tar; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }

            if (dp[tar] == true) {
                return true;
            }
        }

        return false;
    }
};