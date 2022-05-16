#include "LeetCode.h"

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root)
      return "$";

    return to_string(root->val) + "," + serialize(root->left) + "," +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    data += ',';
    string numStr;
    vector<string> nums;
    for (const auto &c : data)
      if (c == ',')
        nums.push_back(numStr), numStr.clear();
      else
        numStr.push_back(c);

    int idx = 0;
    return dfs(nums, idx);
  }

  TreeNode *dfs(vector<string> &data, int &idx) {
    string numStr = data[idx++];
    int i = 0, num = 0;
    if (numStr == "$")
      return NULL;

    bool neg = (numStr[0] == '-');
    if (neg)
      i++;
    for (; i < numStr.size(); i++)
      num = num * 10 + (numStr[i] - '0');
    num = (neg ? -num : num);

    return new TreeNode(num, dfs(data, idx), dfs(data, idx));
  }
};