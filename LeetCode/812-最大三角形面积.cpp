#include "LeetCode.h"

class Solution {
public:
  double ans = 0;

  double area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
  }

  double largestTriangleArea(vector<vector<int>> &points) {
    int n = points.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          ans = max(ans, area(points[i][0], points[i][1], points[j][0],
                              points[j][1], points[k][0], points[k][1]));
        }
      }
    }

    return ans;
  }
};