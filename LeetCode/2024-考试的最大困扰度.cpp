#include "LeetCode.h"

class Solution {
public:
    int maxConsecutiveAnswers(string str, int k) {
       return max(twoPtr(str, k, 'T'), twoPtr(str, k, 'F'));
    }

    int twoPtr(string &str, int k, char c) {
        int n = str.size();
        
        // 滑动窗口(双指针), 尝试以每一个字符结尾
        // 窗口尽可能大即可
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (str[r] != c) {
                k--;
            }

            while (k < 0) {
                if (str[l] != c) {
                    k++;
                }
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};