#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100000005
using unl = __int128_t;
using ll = long long;
using namespace  std;

class Solution {
public: 
    int qmi(ll a, ll b, ll p) // 对 p 取模
    {
       ll res = 1;
       while(b) 
       {
           if (b & 1) res = res * a % p;
           a = (a * a) % p,b >>= 1;
       }
       return res;
    }
    void solve() {
        ll b, p, k; cin >> b >> p >> k; 
        cout << qmi(b,p,k) << endl;
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


// https://www.lanqiao.cn/problems/1514/learning/?page=1&first_category_id=1&name=%E5%BF%AB%E9%80%9F%E5%B9%82
