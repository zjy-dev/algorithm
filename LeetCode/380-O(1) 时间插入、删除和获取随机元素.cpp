#include "LeetCode.h"

class RandomizedSet {
public:
  vector<int> nums;
  unordered_map<int, int> num2loc;
  RandomizedSet() {}

  bool insert(int val) {
    if (num2loc.find(val) != num2loc.end())
      return false;

    num2loc[val] = nums.size();
    nums.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (num2loc.find(val) == num2loc.end())
      return false;

    nums[num2loc[val]] = nums.back();
    num2loc[nums.back()] = num2loc[val];
    nums.pop_back();
    num2loc.erase(val);
    return true;
  }

  int getRandom() { return nums[rand() % nums.size()]; }
};