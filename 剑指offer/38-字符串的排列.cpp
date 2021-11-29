#include"LeetCode.h"

class Solution {
public:
    vector<string> ans;
    vector<bool> vis;
    string s, temp;
    int n;
    vector<string> permutation(string s) 
    {
        sort(s.begin(), s.end());
        this->s = s;
        n = s.size();
        vis.resize(n);
        dfs(0);
        return ans;
    }

    void dfs(int idx)
    {
        if(idx == n)
            ans.push_back(s);

        for(int i = 0; i < n; i++)
        {
            if(vis[i] or (i and s[i] == s[i - 1] and !vis[i - 1]))
                continue;
            
            vis[i] = true;
            temp.push_back(s[i]);
            dfs(idx + 1);
            vis[i] = false;
            temp.pop_back();
        }
    }
};