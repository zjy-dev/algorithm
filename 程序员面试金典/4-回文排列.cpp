#include "LeetCode.h"

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<128> hash;

        for (const auto& c : s) {
            hash.flip(c);
        }

        // 0个奇数和1个奇数是可以接受的
        return hash.count() <= 1;
    }
};