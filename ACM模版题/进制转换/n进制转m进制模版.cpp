#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100005
using unl = __int128_t;
using ll = long long;
using namespace  std;
// 2 - 16
class Solution {
public:
    void slove() {
        int n, m;
        int count = 0;
        string s;
        cin >> n >> s >> m;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 16; j++) {
                if (a[j] == s[i]) {
                    count = count * n + j; //乘与相应权重 -> 转化为10进制
                }
            }
        }
        
        int d[N];
        int i = 0;
        while (count) { 
            d[i] = count % m; // 10进制 转化 -> m 进制
            count /= m; // 除与相应权重
            i++; 
        }
        
        for (int j = i - 1; j >= 0; j--) {
            if (d[j] >= 10)
                cout << (char)(d[j] + 'A' - 10);
            else
                cout << d[j];
        }
    }

private:
    int d[N];
    char a[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
};


signed main() {

    cin.tie(0) -> ios::sync_with_stdio(0);
    cout.tie(0) -> ios::sync_with_stdio(0);

    #if Run
        int _;cin>>_;while(_--) Solution().slove(_);
    #else
        Solution().slove();
    #endif

    return 0;
}
