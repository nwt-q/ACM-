#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100005
using unl = __int128_t;
using ll = long long;
using namespace  std;
int a[6]={1,5,10,20,50,100};
int cnt[6] = {N,N,N,N,N,N};//对应上面的张数

class Solution {
public: // 转换为完全背包问题
     void solve() {
        int money; cin >> money; // 背包容量
        for (int i = 5; i >= 0; i --) { 
            int zhanshu = 0;
            if (money > 0) {
                zhanshu = min(money / a[i],cnt[i]);
                cnt[i] = zhanshu;
            }
            money -= zhanshu * a[i];
        }
        for (int i = 5; i >= 0; i--) {
            if ( cnt[i] > 0&&cnt[i] < N) cout << "需要" << cnt[i] << "张"<< a[i] << "块的" << endl;
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

// https://www.educoder.net/classrooms/ospyjqb4/shixun_homework/1397444/detail?tabs=0
