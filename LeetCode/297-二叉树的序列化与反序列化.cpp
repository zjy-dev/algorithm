#include"LeetCode.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "$";
        
        auto leftStr = serialize(root->left);
        auto rightStr = serialize(root->right);
        return to_string(root->val) + "," + leftStr + "," + rightStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> strs;
        string str;
        for(const auto& c : data)
            if(c == ',')
                strs.push_back(str), str.clear();
            else
                str.push_back(c);
        int a = 0;
        return dfs(strs, a);
    }

    TreeNode* dfs(vector<string>& strs, int& a)
    {
        string str = strs[a++];

        if(str == "$")
            return NULL;
        
        int val = 0;
        bool neg = (str[0] == '-');
        for(int i = neg; i < str.size(); i++)
            val = val * 10 + str[i] - '0';
        val = neg ? -val : val;
        auto root = new TreeNode(val, dfs(strs, a), dfs(strs, a));

        return root;
    }
};
