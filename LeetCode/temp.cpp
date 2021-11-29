#include<bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> temp;
int n;

void dfs(int pos)
{
    if(pos >= n)
    {
        for(const auto& val : temp)
            cout << val << " ";
        puts("");
        return;
    }

    dfs(pos + 1);

    temp.push_back(v[pos]);
    dfs(pos + 1);
    temp.pop_back();
}

int main(int argc, char const *argv[])
{
    v = vector<int>{1, 2, 3, 4, 5, 6, 7, 8};
    n = v.size();
    dfs(0);
}