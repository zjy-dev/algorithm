#include "LeetCode.h"

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 题意可以抽象成求同一时刻同时进行的会议数量的最大值
        // 我们可以讲开始和结束时间混合在一起进行排序, 用cnt表示当前同时进行的会议数
        // 遇到开始时间就cnt++, 遇到结束时间就cnt--即可
        int ans = 0;
        int cnt = 0;

        // false表示结束, true表示开始
        // 这是因为题干认为, a会议结束时间等于b会议开始时间, 则a和b可以共用一间会议室
        // 我也非常无语, 但是用false表示结束来排序的话, 就可以保证b先让出会议室, a再抢占会议室
        // 也就是符合了题干的心意 
        vector<pair<int, bool>> v;

        // 混合开始和结束时间
        for (const auto& val : intervals) {
            v.push_back({val[0], true});
            v.push_back({val[1], false});
        }

        // 排序
        sort(v.begin(), v.end());

        // 求某一时刻同时进行的会议数量
        for (const auto& p : v) {
            // 会议开始
            if (p.second == true) {
                cnt++;
                ans = max(ans, cnt);
            } else { // 会议结束
                cnt--;
            }
        }

        return ans;
    }
};