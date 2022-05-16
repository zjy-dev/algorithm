#include "LeetCode.h"

class Solution {
public:
  int projectionArea(vector<vector<int>> &grid) {
    int n = grid.size();
    int ans = 0;
    for (int x = 0; x < n; x++) {
      int maxY = 0;
      for (int y = 0; y < n; y++) {
        if (grid[x][y] != 0) {
          ans++;
          maxY = max(maxY, grid[x][y]);
        }
      }
      ans += maxY;
    }

    for (int y = 0; y < n; y++) {
      int maxX = 0;
      for (int x = 0; x < n; x++) {
        maxX = max(maxX, grid[x][y]);
      }
      ans += maxX;
    }

    return ans;
  }
};