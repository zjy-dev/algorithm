#include"LeetCode.h"

const int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

class Solution{
public:
    string word;
    int n, r, c;
    vector<vector<char>> board;
    vector<vector<bool>> vis;

    bool exist(vector<vector<char>>& board, string word) 
    {
        this->word = word;
        this->n = word.size();
        this->board = board;
        this->r = board.size(), this->c = board[0].size();
        vis = vector<vector<bool>>(r, vector<bool>(c, false));

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                if (dfs(i, j, 0))
                    return true;
            }
            
        return false;
    }

    bool dfs(int i, int j, int idx)
    {   
        if(word[idx] != board[i][j])
            return false;
        else if(idx == n - 1)
            return true;

        vis[i][j] = true;
        bool ans = false;
        for(int t = 0; t < 4; t++)
        {
            auto x = i + X[t], y = j + Y[t];
            if(x < 0 or x >= r or y < 0 or y >= c or vis[x][y])
                continue;
            
            if (dfs(x, y, idx + 1))
            {
                ans = true;
                break;
            }
        }

        vis[i][j] = false;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> v(1, vector<char>{'a'});
    cout << Solution().exist(v, "a");
    return 0;
}
