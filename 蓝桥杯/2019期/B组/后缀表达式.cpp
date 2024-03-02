#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100005
using unl = __int128_t;
using ll = long long;
using namespace  std;

class Solution {
public: 
     void solve() {
        ll n,m; 
        while(cin >> n >> m) {
            vector<ll>a(n + m + 5);
            ll res = 0;
            for (ll i = 1; i <= n + m + 1; i++) cin >> a[i];
            sort(a.begin() + 1,a.begin() + n + m + 1);
            if(!m) {
                for (ll i = 1; i <= n + m + 1; i++)  res += a[i];
            } else {
                res = a[n + m + 1] - a[1];
                for (ll i = 2; i <= n + m; i++) res += a[i];
            }
            cout << res << endl;
        }
    }
};

signed main() {

    cin.tie(0) -> ios::sync_with_stdio(0);
    cout.tie(0) -> ios::sync_with_stdio(0);

    #if Run
        int _;cin>>_;while(_--) Solution().solve();
    #else
        Solution().solve();
    #endif

    return 0;
}
// -( - ... - ); // 最小减去一个
