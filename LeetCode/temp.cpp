#include<bits/stdc++.h>
using namespace std;

const int maxn = 200 + 5;

int r, c;

int arr[maxn][maxn];

int search(int x, int y)
{
    int t = arr[x][y], cnt = 1;
    while(true)
    {
        if(x + cnt > r or y + cnt > c)
            break;
        
        bool ok = true;
        for(int i = y; i <= y + cnt; i++)
            if(arr[x + cnt][i] != t)
            {
                ok = false;
                break;
            }

        if(!ok)
            break;
        
        for(int i = x; i <= x + cnt; i++)
            if(arr[i][y + cnt] != t)
            {
                ok = false;
                break;
            }

        if(ok)
            cnt++;
        else
            break;
    }

    return cnt * cnt;
}

int main()
{
    scanf("%d%d", &r, &c);
    memset(arr, 0, sizeof arr);

    for(int i = 1; i < r; i++)
        for(int j = 1; j <= c; j++)
            scanf("%d", &arr[i][j]);
    
    int ans = 1;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            ans = max(ans, search(i, j));
    
    cout << ans;
}