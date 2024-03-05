#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 105
using ll = long long;
using namespace  std;
ll a[N + 1];
ll b[N + 1];

void slove() {
    ll n;cin >> n;
    a[0] = 0;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll j = 1; j <= n; j++) b[j] = a[j] + b[j - 1];
    if (b[n] % 2 == 0) cout << "Bob";
    else cout << "Alice";
    
}


int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    cout.tie(0) -> ios::sync_with_stdio(0);
    #if Run
        int _;cin>>_;while(_--) slove();
    #else 
        slove();
    #endif
    return 0;
}
