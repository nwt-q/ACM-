#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100005
using unl = __int128_t;
using ll = long long;
using namespace  std;
class Solution {
public: //就是一个数的所有公倍数
    void slove() {
        int ans = 0;
        int n,m; cin >> n >> m;
        for (int i = n; i <= m; i++) {
            if (isGood(i)) ans++;
        }
        cout << ans << endl;
    }
    bool isGood(int x) {
        int sum = 0;
        for (int i = 1; i < x; i++) {
            if (x % i == 0)  sum += i;
        }
        if (sum == x) return true;
        else return false;
    }

};


signed main() {

    cin.tie(0) -> ios::sync_with_stdio(0);
    cout.tie(0) -> ios::sync_with_stdio(0);

    #if Run
        int _;cin>>_;while(_--) Solution().slove();
    #else
        Solution().slove();
    #endif

    return 0;
}
