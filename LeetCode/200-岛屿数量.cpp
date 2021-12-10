#include"LeetCode.h"

const int posX[4] = {0, 0, 1, -1}, posY[4] = {-1, 1, 0, 0}; 

class Solution {
public:
    vector<int> p;

    int find(int u)
    {
        if(p[u] != u)
            p[u] = find(p[u]);
        return p[u];
    }

    void unionPoint(int a, int b)
    {
        p[find(a)] = find(b);
    }

    int numIslands(vector<vector<char>>& matrix) 
    {
        int r = matrix.size(), c = matrix[0].size();
        p.resize(r * c + 10);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                auto t = i * c + j;
                p[t] = (matrix[i][j] == '1') ? t : -1;
            }
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(matrix[i][j] == '1')
                    for(int t = 0; t < 4; t++)
                    {
                        auto x = posX[t] + i, y = posY[t] + j;
                        if(x < 0 or x >= r or y < 0 or y >= c or matrix[x][y] == '0')
                            continue;
                        
                        unionPoint(i * c + j, x * c + y);
                    }
        
        unordered_set<int> s;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                s.insert(find(i * c + j));
            }
        
        return s.size();
    }
};