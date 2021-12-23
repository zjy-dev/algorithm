#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void quick_sort(int l, int r)
{
    //一个数据就不需要排了
    if(l >= r)
        return;

    int i = l - 1, j = r + 1, flag = v[l + r >> 1];

    while(i < j)
    {
        while(v[++i] < flag);
        while(v[--j] > flag);
        if(i < j)
            swap(v[i], v[j]);
    }

    //以j为界, [l, j] <= flag, [j + 1, r] >= flag
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main(int argc, char const *argv[])
{
    v = {3, 1, 2, 4, 5};
    quick_sort(0, v.size() - 1);
    for(const auto& val : v)
        cout << val << " ";
    return 0;
}