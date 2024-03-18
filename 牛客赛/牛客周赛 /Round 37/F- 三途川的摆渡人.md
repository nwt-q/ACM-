
## [三途川的摆渡人](https://ac.nowcoder.com/acm/contest/77231/F)

>思路: 用桶的思想存储每个数据,然后对数据进行类背包dp , 当然也可以回溯算法进行解决

```cpp
#include<bits/stdc++.h>
#define Run 1
#define endl "\n"
#define mod 495
using ll = long long;
using namespace std;

class Solution {
public: 
    void solve()  // 类背包dp 某值区较小
    {
        int n,x; std::cin >> n;
        std::memset(tong, 0, sizeof tong);
        for (int i = 0; i < n; i++) std::cin >> x,tong[x]++;
        std::memset(dp,0x3f,sizeof dp);
        for (int i = 0; i <= 200; i++) {
            if (tong[i]) {
                dp[i][1] = 1;
                for (int j = 0; j <= 200; j++) {
                    dp[i & j][1] = std::min(dp[i & j][1],dp[j][0] + 1);
                }
                for (int j = 0; j <= 200; j++) {
                    dp[j][0] = dp[j][1];
                }
            }
        }
        if (dp[0][0] > n) std::cout << -1 << '\n';
        else std::cout << n - dp[0][0] << '\n';
    }
private:
    int tong[202];
    int dp[202][2];
};

signed main() {
    std::cin.tie(0) -> std::ios::sync_with_stdio(false);
    std::cout.tie(0) -> std::ios::sync_with_stdio(false);
    
#if Run
    int _;std::cin>>_;while(_--) Solution().solve();
#else
    Solution().solve();
#endif
    return 0;
}
```
