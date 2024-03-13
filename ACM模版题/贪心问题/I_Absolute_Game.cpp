#include<bits/stdc++.h>
using ll = long long;
#define Run 0
#define N 1010
#define inf 0x3f3f3f3f
#define endl "\n"
int a[N];int b[N];

void slove(){
    ll n; std::cin >> n;
    std::vector<ll>a(n + 10,0),b(n + 10,0);
    for (auto i = 0; i < n; i++) std::cin >> a[i];
    for (auto i = 0; i < n; i++) std::cin >> b[i];
    ll ans = 0;
    for (auto i = 0; i < n; i++) {
        ll tmp = inf;
        for (auto j = 0; j < n; j++) {
            tmp = std::min(tmp,std::abs(a[i] - b[j]));
        }
        ans = std::max(ans,tmp);
    }
    std::cout << ans << endl;
}

signed main() {
    std::cin.tie(0) -> std::ios::sync_with_stdio(0);
    std::cin.tie(0) -> std::ios::sync_with_stdio(0);
#if Run
    int _; std::cin>>_; while(_ --> 0) slove();
#else
    slove();
#endif
    return 0;
}
