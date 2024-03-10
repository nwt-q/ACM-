#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100005
#define FOR(i, j, k) for(auto i(j); i <= (k); ++i)
#define ROF(i, j, k) for(int i(j); i >= (k); --i)
#define pii std::pair<int,int>
#define pll std::pair<ll, 1l>
#define ALL(v) (v).begin(),(v).end()
using unl = __int128_t;
using namespace std;
using ll = long long;

class TransForm { //进制转换
public: 
    string intToA(int n, int radix) {   // n是待转换的数字 radix  进制 10 是指定的进制
        if (n == 0) return "0"; // 当n为0时，直接返回"0"

        string ans = "";
        do {
            int t = n % radix; //取模权重
            if (t >= 0 && t <= 9) ans += t + '0'; // 这个是用于 2 - 10 进制内的进制转换 转换为字符串
            else ans += t - 10 + 'A';    //大于10进制转换为字母所以要 +  'A' 转换为字符串
            n /= radix;
        } while (n > 0);

        reverse(ans.begin(), ans.end());

        return ans;
    }

public:
    long int AToB(string s,int radix) {
        
        return strtol(s.c_str(), nullptr, radix);
    }
public:
    void MAIN() {
        int n,m; // n为转换为m进制
        string s; cin >> n >> s >> m; 
        ll A = AToB(s,n); //n进制转换为10进制
        string t = intToA(A,m); //10 进制转换为m 进制
        cout << t << endl;
    }
};


// void Money() { //钱币找零
//     int money; cin >> money; // 背包容量
//     for (int i = 5; i >= 0; i --) { 
//         int zhanshu = 0;
//         if (money > 0) {
//             zhanshu = min(money / a[i],cnt[i]);
//             cnt[i] = zhanshu;
//         }
//         money -= zhanshu * a[i];
//     }
//     for (int i = 5; i >= 0; i--) {
//         if ( cnt[i] > 0&&cnt[i] < N) {cout << "需要" ;cout << cnt[i]; cout << "张"; cout << a[i]; cout << "块的" << endl;}
//     }
// }

bool Find(ll n) {
      
    std::string s = std::to_string(n);   //数字转化为字符串,字符串转化为数字 ( -'0' ) 或者通过函数

    if (s.find("233") != std::string::npos) return true;  //KMP查找字符串

    return false;  
    
}

//思路提供: 
//去重
// sort(ALL(ans));
// ans.erase(unique(ALL(ans)), ans.end());
 // isdigit();判断是否为数字
 //多个变量尽量通过关系用一个变量表示

class Solution {
public: 
    void solve() {
       ll n,m,q; std::cin >> n >> m >> q;
       std::vector<std::vector<ll>> a(n + 10,std::vector<ll>(m + 10)),b(n + 10,std::vector<ll>(m + 10));
       FOR(i,0,n - 1) FOR(j,0,m - 1) std::cin >> a[i][j];
       while(q --> 0) {
           ll x, y, xx, yy, c; std::cin >> x >> y >> xx >> yy >> c;
           x--,y--,xx--,yy--;
           b[x][y] += c;
           b[xx + 1][y] -= c;
           b[x][yy + 1] -= c;
           b[xx + 1][yy + 1] += c;
       }
       FOR(i,0,n - 1) FOR(j,0,m - 1) b[i + 1][j] += b[i][j];
       FOR(i,0,n - 1) FOR(j,0,m - 1) b[i][j + 1] += b[i][j];
       FOR(i,0,n - 1) FOR(j,0,m - 1) a[i][j] += b[i][j];
       FOR(i,0,n - 1) FOR(j,0,m - 1) std::cout << a[i][j] << " \n"[j == m - 1]; 
    }
public: //最小公倍数
     int lcm(int a, int b)
    {
        return (a * b) / gcd(a, b);
    }
    //最大公约数
    int gcd(int a, int b) {
        return b > 0 ? gcd(b,a % b) : a;
    }
public:
    int IsPrime(int n)  //质数判断
    {
        int i;
        if(n<2||(n!=2&&n%2==0))//n小于2或者n是不等于2的偶数，必然非素数
            return 0;
        else//这里n都是奇数
        {//这里使用上面刚提到的写法，用i代替开根号的过程
            for(i=3;i*i<=n;i+=2)//这里注意循环条件
            {//2必然不是因子，从3开始，每次递增2，直到sqrt(n)为止
                if(n%i==0)
                    return 0;
            }
            return 1;
        }
    }
public: //快速幂
    int qmi(ll a, ll b, ll p) // 对 p 取模 a的b次幂
    {
       ll res = 1;
       while(b) 
       {
           if (b & 1) res = res * a % p;
           a = (a * a) % p,b >>= 1;
       }
       return res;
    }
public:
    int ShU(int n) {
        ll ans = 0;
        while(n) {
            ans += (n % 10);
            n /= 10;
        }
        return ans;
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

//https://www.lanqiao.cn/courses/21967/learning/?id=1337922&compatibility=false
