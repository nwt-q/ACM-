#include <bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100000
using unl = __int128_t;
using ll = long long;
using namespace std;

class Solution
{
public:
    void slove()
    {
        string ch;
        while (cin >> ch)
        { // 以字符的方式读入
            int ans[100000];
            int len = 0, d = 0, t = 0;
            for (int i = ch.size() - 1; i > 1; i--)
            {
                d = ch[i] - '0'; // 将字符转换为数字
                // d用来储存每一位的数字
                int k = 0, j = 0;

                while (j < t || d)
                {
                    d = d * 10 + ans[j++];  //这里在执行进制转换算法
                    ans[k++] = d / 8;  //最后的数储存在ans中
                    d = d % 8;
                }
                t = k; //储存遍历次数
            }
            cout << ch << " " 
                 << "[8]"
                 << " "
                 << "="
                 << " "
                 << "0.";

            for (int i = 0; i < t; i++)  //输出ans中的值
            {
                cout << ans[i];
            }
            cout << " " << "[10]" << endl;
            for (int i = 0; i < t; i++)  
            {
                ans[i] = 0;  //清空数据到下一个数据来
            }
        }
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
