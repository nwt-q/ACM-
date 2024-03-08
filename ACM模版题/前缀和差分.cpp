#include<bits/stdc++.h>
#define Run 1
#define endl "\n"
#define N 100005
using unl = __int128_t;
using namespace std;
using ll = long long;


class Solution {
public: 
    void solve() {
        ll n; std::cin >> n;
        while(n++) {
            if (isGood(n)) {
                std::cout << n << endl;
                return ;
            }
        }
    } 
    
    bool isGood(ll n) {
        std::string s = std::to_string(n);  

        if (s.find("233") != std::string::npos) return true;  

        return false;  
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
//https://www.lanqiao.cn/courses/21967/learning/?id=1337921&compatibility=false
