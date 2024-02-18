#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100005
using unl = __int128_t;
using ll = long long;
using namespace  std;
int a[N];
char str[27]={0,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


class Solution {
public:
    void slove(auto _) {
    int n; cin >> n;
    a[3] = 2; a[4] = 3;
    for (int i = 5; i <= N; i++) {
        if ((i % 3 && (i + 1) % 3) || i % 3 == 0) {
            a[i] = a[i - 1] + 1;
        } else {
            a[i] = a[i - 1];
        }
    }
    cout << a[n] << endl;
    }

    void decimalTo26(ll n) {
    string result;
    while (n > 0) {
        ll remainder = n % 26;
        if (remainder == 0) {
            result = 'Z' + result;
            n = (n / 26) - 1;
        } else {
            result = str[remainder] + result;
            n = n / 26;
        }
    }
        cout << result << endl;
    }

};

signed main() {

    cin.tie(0) -> ios::sync_with_stdio(0);
    cout.tie(0) -> ios::sync_with_stdio(0);

    #if Run
        auto _;cin>>_;while(_--) Solution().slove(_);
    #else
        ll _; while(cin >> _) Solution().decimalTo26(_);
    #endif

    return 0;
}
