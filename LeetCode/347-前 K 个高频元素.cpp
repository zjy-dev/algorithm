#include "LeetCode.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计出现次数
        unordered_map<int, int> hash;
        for (const auto& val : nums) {
            hash[val]++;
        }

        // pair.first存频率, second存数字
        // 小顶堆, 这样可以按照频率从小到大排序
        // 接下来就是topk了, 有手就行
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (const auto& p : hash) {
            if (q.size() < k) {
                q.push({p.second, p.first});
            } else {
                if (p.second > q.top().first) {
                    q.pop();
                    q.push({p.second, p.first});
                }
            }
        }

        // ans中存的是pair.second也就是数字部分!
        vector<int> ans;
        while (q.empty() == false) {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};