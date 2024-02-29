#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100000005
using unl = __int128_t;
using ll = long long;
using namespace  std;

class Solution {
public: // A -> T C -> G
    void solve() {
        int n; cin >> n;
        int ans = 0;
        string s, t; cin >> s >> t;
        for (int i = 0; i < n; i++) {
            if(TO(s[i]) == t[i]) continue;
            for(int j = 0; j < n; j++) {
                if(TO(s[i]) == t[j] && TO(s[j]) == t[i]) {
                    swap(s[i],s[j]);
                    break;
                }
            } 
            ans++;
        }
        cout << ans << endl;      
    }   
    char TO(char a) {
        switch(a) {
            case 'A': return 'T';
            case 'C': return 'G';
            case 'T': return 'A';
            case 'G': return 'C';
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

// 蓝桥杯
