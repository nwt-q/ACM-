#include<bits/stdc++.h>
#define Run 1
#define endl "\n"
#define N 100000005
using unl = __int128_t;
using ll = long long;
using namespace  std;

class Solution {
public: 
    int qmi(int a, int b, int p) // 对 p 取模
    {
        int res = 1;
        while(b) 
        {
            if (b & 1) res  = res * a % p; // b 为奇数,乘一个a到答案里
            a = a * a, b >>= 1; // 底数平方 , 指数除以2
        }
        return res;
    }
    void solve() {
        int n; cin >> n;
        int zero = 0, sum = 0; //之和之积不为0
        /*
        *1. 乘积不为 0 就不能出现 0 
        *2. 之和不为 0 判断 sum 是否等于 0 如果等于 0 则对任意数 + 1
        */
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 0) zero++;
            sum += x;
        }
         if ( (sum + zero) == 0) cout << zero + 1 << "\n";
         else cout << zero << '\n';
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

// https://www.lanqiao.cn/problems/3238/learning/?page=1&first_category_id=1&name=%E5%B0%8F%E8%93%9D%E5%92%8C%E5%B0%8F
