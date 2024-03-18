## [迷途之家的大贤者](https://ac.nowcoder.com/acm/contest/77231/D)

>思路: 每次都取最优,上次最大的然后留下边界最小的让后面没有办法操作

```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 1000
using ll = long long;

int dp[10]; // 0 - 9的下标

class Solution {
public: 
     void solve() {
        std::string s; ll n;
        std::cin>>n>>s;
        std::cout << std::max(s[0],s.back());
        return ;
    }
};


signed main() {
    std::cin.tie(0) -> std::ios::sync_with_stdio(false);
    std::cout.tie(0) -> std::ios::sync_with_stdio(false);
    
#if Run
    int _;std::cin>>_;while(_--) Solution().Solve();
#else
    Solution().solve();
#endif
    return 0;
}

```
