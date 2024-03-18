
## [红魔馆的馆主](https://ac.nowcoder.com/acm/contest/77231/C)

> 思路: 对 n 取模, 然后将取模数的当成前缀,去 495 的倍数中找与之相等前缀的公倍数,这样就能找到答案,然后输出后面的几个数即答案



```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define mod 495
using ll = long long;
using namespace std;

class Solution {
public: 
    void solve() {
        ll n; std::cin >> n; 
        if (n % mod == 0) {
            std::cout << -1 << endl;
        }
        std::string t = to_string(n % mod); // 取模,这个什么神器的思路?
        ll b = t.size();
        for (ll i = 1; ; i++) {
            ll m = mod * i;
            std::string k = std::to_string(m);
            if (k.substr(0,b) == t) {
                std::cout << k.substr(b) << endl;
                return ;
            }
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


>思路2 : 深度优先搜索

```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
using ll = long long;
using namespace std;
class Solution {
public: 
    void solve() {
        ll n; std::cin >> n;
        if (n % 495 == 0) {
            std::cout << -1 << endl;
            return ;
        }
        ll tmp = n;
        for (ll i = 1; i <= 4; i++) {
            if (dfs(i,0,n)) break; 
        }
        std::cout << path << "\n";
       
    } // dfs遍历查找区间
    bool dfs(ll cur, ll depth, ll t) {
        if (cur == depth) {
            if (t % 495 == 0) return true;
            
            return false;
        }
        for (ll i = 0; i <= 9; i++) {
            path += to_string(i);
            ll tm = ((t % 495 * 10 % 495) + i ) % 495;
            if (dfs(cur, depth + 1, tm)) return true;
            path.pop_back();
        }
        return false;
    }
private:
    std::string path = ""; 
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
