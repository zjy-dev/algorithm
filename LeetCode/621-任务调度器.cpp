#include "LeetCode.h"

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    // 统计每一个任务的数量
    unordered_map<char, int> hash;
    for (const auto &c : tasks) {
      hash[c]++;
    }

    // 任务种类数
    int typeSize = hash.size();

    // rest表示某任务剩余的数量, nextValid表示某任务最早什么时候能执行
    vector<int> rest, nextValid;
    for (const auto [_, val] : hash) {
      rest.push_back(val);
      nextValid.push_back(1);
    }

    int ans = 0;

    // 将每一个任务都执行掉
    for (int i = 0; i < tasks.size(); i++) {
      // 执行一个任务, 运行时间++
      ans++;

      // 可能需要跳过空转时间, 即所有任务都cd的时间
      // 因此需要查出最早合法的一个任务
      // 如果最早合法的任务比ans大, 那么也就说明出现了空转
      int minNextValid = INT_MAX;
      for (int j = 0; j < typeSize; j++) {
        if (rest[j] > 0) {
          minNextValid = min(minNextValid, nextValid[j]);
        }
      }
      ans = max(ans, minNextValid);

      // 如果好几个任务的valid时间都 <= ans, 那我们就使用剩余最多的, 用best记录
      int best = -1;
      for (int j = 0; j < typeSize; j++) {
        // 小于等于ans的
        if (rest[j] > 0 && nextValid[j] <= ans) {
          if (best == -1 || rest[best] < rest[j]) {
            best = j;
          }
        }
      }

      // 考虑cpu的cd时间, best任务在ans时刻执行, 而cd时间是n秒
      nextValid[best] = ans + n + 1;

      // best的余量减一
      rest[best]--;
    }

    return ans;
  }
};