
## [雾之湖的冰精](https://ac.nowcoder.com/acm/contest/77231/A)

>解题思路: 输入 n, m 如果 n + m 大于 9 输出 NO 小于 9 输出 YES

```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
using ll = long long;

class Solution {
public: 
    void solve() {
       int n,m;std::cin >> n >> m;
        if (n + m > 9) {
            std::cout << "No\n";
            return ;
        }
        std::cout << "Yes\n";
    }
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
