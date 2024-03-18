
## [博丽神社的巫女](https://ac.nowcoder.com/acm/contest/77231/B)

>解题思路: 将数组排序,然后逐步比较当数组a[i]大于 x 时 则前面的数据为满足魔女的最大数,注意下标从 0 开始 数量为 j + 1

```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
using ll = long long;

class Solution {
public: 
    void solve() {
        int n,x; std::cin >> n >> x;
        std::vector<ll> a(n);
        for (auto & x: a) std::cin >> x;
        std::sort(a.begin(),a.end());  // 排序
        ll j = -1; 
        for (int i = 0; i < n; i++) {
            if (x >= a[i]) { //比交大小只要大于输出下标 + 1即最大魔女数
                j = i;
            }
        }
        if (j == -1) {
            std::cout << 0 <<" "<< x << endl;
        } else {
            std::cout << j + 1 << " " << x - a[j] << endl;
        }
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

