

## [魔法之森的蘑菇](https://ac.nowcoder.com/acm/contest/77231/E)

> 思路: 创建3位数组,进行 bfs遍历, 每一层数组只能往一个方向运动, 当遇到 '#' 时 进入到对应的层 进行运动

```cpp
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int N = 1010;

char g[N][N][4];

int px[4] = {-1,0,1,0};
int py[4] = {0,1,0,-1};

int dp[N][N][4];

void solve()
{
    int n,m; cin >> n >> m;
    int sx,sy,ex,ey;
    memset(dp,0x3f,sizeof dp);
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
        {
            char c; cin >> c;
            for(int p = 0 ; p < 4 ; p ++)
                g[i][j][p] = c;
            if(g[i][j][1] == 'S')
                sx = i,sy = j;
            if(g[i][j][1] == 'T')
                ex = i,ey = j;
        }
    for(int i = 0 ; i < 4 ; i ++)
        dp[sx][sy][i] = 0;
    queue<vector<int>> q;
    for(int i = 0 ; i < 4 ; i ++)
        q.push({sx,sy,i});
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        int x = t[0],y = t[1],p = t[2];
        int xx = x + px[p] ,yy = y + py[p];
        if(xx <= 0 || xx > n || yy <= 0 || yy > m || g[xx][yy][p] =='#')
            continue;
        if(g[xx][yy][p] == '.')
        {
            if(dp[xx][yy][p] > dp[x][y][p] + 1)
            {
                dp[xx][yy][p] = dp[x][y][p] + 1;
                q.push({xx,yy,p});
            }
        }
        else 
        {
            for(int i = 0 ; i < 4 ; i ++)
            {
                //if((i ^ p) == 0) continue;
                if(dp[xx][yy][i] > dp[x][y][p] + 1)
                {
                    dp[xx][yy][i] = dp[x][y][p] + 1;
                    q.push({xx,yy,i});
                }
            }
        }
    }
    int res = 0x3f3f3f3f;
    for(int i = 0 ; i < 4 ; i ++)
        res = min(dp[ex][ey][i],res);
    if(res != 0x3f3f3f3f) cout << res << '\n';
    else cout << -1 << '\n';
}

int main()
{
    int t; cin >> t; 
    while( t --)
    {
        solve();
    }
}
```
