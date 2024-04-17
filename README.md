# 二维数点





# 二分

可以使用C++的库函数:  

`binary_search(arr.begin(),arr.end(),target)` 用于判断元素是否在数组内

`lower_bound(arr.begin(),arr.end(),target)`  用于查找大于等于该元素的第一个元素,返回迭代器 减去 `arr.begin()` 即是数组下标

同理 `upper_bound(arr.begin(),arr.end(),target)` 查找第一个大于 target 的元素同样返回迭代器同样操作



正常二分查找 (整数二分) 

```cpp
int l = 0, r = n - 1;
while (l < r) {
    int mid = (r - l) / 2 + l;
    if (a[mid] > target) {
        r = mid - 1;
    } else if (a[mid] < target) {
        l = mid + 1;
    } else {
        l = mid;
        break;
    }
}
std::cout << l << std::endl;
```



问题二分查找的左开右闭, 与闭区间的区别?

二分查找左右区间不对可能简单样例是对的,数据量大或者数据偏差便可能超时



## 二分答案



二分答案最大困难: 如何将数据二分



模版

```cpp
ll l = 0, r = LLONG_MAX;
whil(l + 1 < r) {
    ll mid = (l + r) >> 1;
    if (cheak(mid)) {
        l = mid; // 最后满足条件位置
    } else {
        r = mid - 1
    }
}
std::cout << l << std::endl;
```



浮点二分

```cpp
while(r-l>1e-5) //需要一个精度保证
{
    double mid = (l+r)/2;
    if(check(mid)) l=mid; //或r=mid;
    else r=mid; //或l=mid;
}
```

二分答案题

[可凑成的最大花束数 ](https://www.lanqiao.cn/courses/21967/learning/?id=1337942&compatibility=false) 


![image](https://github.com/nwt-q/ACM-/assets/143036993/68b8e568-4a88-46e4-8a70-0e5b47939ce8)



```cpp
#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

// 怎么样将问题转换为二分查找类型? 
// 二分查找一定是区间型查找 区间左右区间 l = 0. r = INT_MAX;
// 推出中间值 mid = (r - l ) / 2 + l; 
// 终止条件 l + 1 != r; 

int sum = 0; // 用于统计花的数量 
int n, k; // 将数据设计在此处减少参数 

//怎么样去写条件? 什么情况下不满足条件 
bool check(int mid, vector<int> &a) {
	if(mid > sum / k) return false; // 排除一个条件剩下不满足的条件怎么判断, 或者满足的条件
	// bool 类型只要俩钟一种满足条件一种不满足条件
    // 根据难易程度确定查找true 还是false 注意特殊情况
	int cnt = 0;
    //中间值确定便考虑左右俩边的值是否正确
	for(const auto &x : a) { // 小于 mid 加上原值 , 大于mid 加上 mid  
		cnt += std::min((int)x , mid); 
	}
	if(cnt / k >= mid) return true;
	else return false;	
}


void solve() {
	std::cin >> n >> k;
	vector<int> a(n);
	for(auto &x : a) {
		std::cin >> x;
		sum += x; 
	}
	int l = 0, r = LLONG_MAX;
	while(l <= r) { //注意二分查找的区间的区别
		int mid = (r - l) / 2 + l;
		if(check(mid,a)) l = mid + 1;
		else r = mid - 1; 
	}
	std::cout << l - 1<< endl;
}


signed main(){
	int T = 1;
	for(int i = 1; i <= T; i++) solve();
} 
```



```cpp
#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

// 怎么样将问题转换为二分查找类型? 
// 二分查找一定是区间型查找 区间左右区间 l = 0. r = INT_MAX;
// 推出中间值 mid = (r - l ) / 2 + l; 
// 终止条件 l + 1 != r; 
int n, k;

bool check(int mid, vector<int> &a) {
    int cnt = 0;
    for (const auto &x : a) {
        cnt += std::min((int)x, mid);
    }
    if (cnt / k >= mid) return true;
    else return false;
}

// Day 2 bug 俩问题
/*
1. return false 不能 false
2. 记得开long long 也要开最大的 LLONG_MAX , 不能INT_MAX; 会出错
*/

void solve() {
    std::cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) {
        std::cin >> x;
    }

    int l = 0, r = LLONG_MAX; // 最大值问题
    while(l <= r) {
        int mid = (r - l) / 2 + l;
        if(check(mid,a)) l = mid + 1;
        else r = mid - 1;
    }
    std::cout << l - 1 << endl;
}


signed main(){
    int T = 1;
    for(int i = 1; i <= T; i++) solve();
} 
```







# 双指针

什么是双指针?

双指针是用下标表示元素,移动的时候有左右边界,对边界的操作方法,其实二分也算是双指针的操作方法

双指针是对区间的一种操作

双指针的操作方法

- 一般双指针: 有俩指针 , 一个指针指向数组的头,一个指向数组的尾部
- 同向双指针: 按照同一个方向前进,但是指针快慢不同
- 指向不同对象的双指针: 对元素进行查找,判断一个序列是否是另一个序列的子序列,可以分别指向序列1 和 序列 2 然后将然后当俩序列指针指向元素相同时进行指针移动,最后当一个指针指向结尾时一个指针同样指向结尾则表示是子序列,当一个指向结尾一个未指向结尾(要判断的那个序列) 则不是子序列
- 链表环内进行指针查找 : 循环链表规律: 快慢指针指向同一点时,另一个指针从头结点出发,交点指针也出发,最后头节点出发的指针于交点指针向交的地方即环的出口





# 快速幂

**标准快速幂**

```cpp
ll qmi(ll a, ll b, ll p) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % p;
        a = a * a % p; b >>= 1;
    }
    return res;
}
```



[3.djwcb【算法赛】 - 蓝桥云课 ](https://www.lanqiao.cn/problems/17028/learning/?contest_id=177)

**高精度快速幂**



```cpp
#include<bits/stdc++.h>
#define Run 1
#define endl "\n"
using ll = long long;
using namespace  std;



class Solution {
public: 
    void slove() {
        ll n; std::cin >> n;
        string s; std::cin >> s;
        std::cout << qmi(n,10,s) << endl;
    }
    ll qmi(ll x, ll b,string p) {
        ll res = 1;
       for (int i = p.size() - 1; i >= 0; --i) {
           int digit = p[i] - '0';
           ll temp = 1;
           for (int j = 0; j < digit; j++) {
               temp = (temp * x) % b;
           }
           res = (res * temp) % b;
           x = (x * x) % 10;
       }
        return res;
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
```





**高精度快速幂变异版**


![image](https://github.com/nwt-q/ACM-/assets/143036993/888c344d-7618-4fd8-88e9-198f11b8901f)



```cpp
#include<bits/stdc++.h>
using namespace std;

int _pow(int a,int n,int p)//求a^n普通幂,对p取模
{
    int res=1;
    while(n--)res=res*a%p;
    return res;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int x;
        string p;
        cin>>x>>p;
        
        int ans=1;
        for(int i=p.size()-1;i>=0;i--)//倒序遍历
        {
            ans=(ans*_pow(x,p[i]-'0',10))%10;
            x=_pow(x,10,10)%10;//每一次 x=x^10
        }
        cout<<ans<<endl;
    }

    return 0;
}
```





# STL常忘

##  priority_queue() (堆)

堆的操作

- push(x)
- pop()
- top()
- empty()
- size()

题目链接 : [1.合并果子 - 蓝桥云课](https://www.lanqiao.cn/problems/741/learning/?page=1&first_category_id=1&name=合并果子)

堆的运用题代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ll n; std::cin >> n;
  priority_queue<ll,std::vector<ll>,greater<ll>> pq;
  for (ll i = 0; i < n; i++) {
      ll x; std::cin >> x;
      pq.push(x);
  }

  ll res = 0;
  while(pq.size() >= 2) {
      ll x = pq.top();pq.pop();
      ll y = pq.top();pq.pop();
      res += x + y;
      pq.push(x + y);
  }

  std::cout << res << "\n";

  return 0;
}
```



堆的要素: 选择容器一般为 vector 然后是排序规则默认为大根堆



## set



```cpp
set<T> name;
```



**set不支持下标访问**









## 倍增



```cpp
#include<bits/stdc++.h>
using namespace std;
#define maxn 110000
#define ll long long
int n, a[maxn], f[maxn][40];
int query (int l, int r)
{
    int k = (int)(log((r - l + 1) * 1.0) / log(2.0));
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i )
        scanf("%d", &a[i]), f[i][0] = a[i];
    for (int j = 1; j <= (int)(log(n * 1.0) / log(2.0)); ++ j )
        for (int i = 1; i + (1 << j) - 1 <= n; ++ i )
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    int q;
    scanf("%d", q);
    while (q -- )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    
    return 0;
}
```



倍增2



```cpp
#include<bits/stdc++.h>
using namespace std;
#define maxn 110000
int n, q;
int head[maxn], cnt;
struct Edge{
    int nex, to;
}edge[maxn<<1];
void add(int from, int to)
{
    edge[++cnt].nex = head[from];
    head[from]=cnt;
    edge[cnt.to] = to;
    return ;
}
int dep[maxn], fa[maxn][30];
void dfs(int x, int f)
{
    dep[x] = dep[f] + 1;
    fa[x][0] = f;
    for (int i = head[x]; i; i = edge[i].nex )
    {
        int v = edge[i].to;
        if (v == f)
            continue;
        dfs(v, x);
    }
    return ;
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 20; i >= 0; i -- )
        if (dep[fa[x][i]] >= dep[u])
            x = fa[x][i];
    if (x == y)
        return x;
    for (int i = 20; i >= 0; i -- )
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);add(b, a);
    }
    dfs(1, 0);
    for (int j = 1; j <= 20; ++ j )
        for (int i = 1; i <= n; i ++ )
        {
             fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    int q;
    scanf("%d", &q);
    while (q -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
```







# 动态规划



## 线性dp



## 背包问题

### 01背包

假设我当前背包容量为 V 我能够装下容量为 v 物品, (V-v ) 这个状态的背包容量的最优情况进行 + w 的操作



[01背包问题](https://www.acwing.com/problem/content/2/)



```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define n 105
#define m 1010
using ll = long long;
using namespace  std;
ll dp[n][m];


void slove() {
    ll N,V;cin >> N >> V; //这个是物品数 N 背包体积V
    for (int i = 1 ; i <= N; i++) {
        ll w,v;cin >> w >> v; //每个物品的 重量 和 价值
        for (int j = 0; j <= V; j++) {
            if (j >= w) dp[i][j] = max(dp[i-1][j],dp[i - 1][j - w] + v); //递推公式(动态转移方程)
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][V] << endl;
}


int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    cout.tie(0) -> ios::sync_with_stdio(0);
    #if Run
        int _;cin>>_;while(_--) slove();
    #else 
        slove();
    #endif
    return 0;
}
```





### 完全背包

物品无限个



### 多重背包

物品数量被限制





## 树形dp



## 区间dp



**普通区间dp**

区间dp个人理解: 

通过枚举相邻区间的每种情况,在每种情况中,保留当下区间最优情况,然后将当下最优传递到更大的区间中保证大区间的最优情况。

只要有顺序的合并一般为区间dp

区间dp的操作方法

- 从小到大枚举区间长度
- 对于一段区间,枚举这段区间内的所有情况
- 对于每一种情况,枚举出每段区间所有子序列
- 在子序列中寻找当前区间的最优解



区间dp运用了分治的思想,贪心的策略,以动态规划的方式储存



*动态规划最难部分: 状态转移方程的确定*



**区间dp模板**

```cpp
const int MAX = 210;

class Solution {
public: 
    void solve() {
        int n;std::cin >> n;
        std::vector<int> a(n,0);
        memset(dp,127,sizeof dp);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            a[i] += a[i - 1];
            dp[i][i] = 0; // 长度为 1 的区间不需要合并 代价为 0 
        }
        for (int len = 2; len <= n; len++) { // 枚举区间长度
            for (int i = 1; i + len - 1 <= n; i++) { // 枚举起点
                int j = i + len - 1; // 通过长度计算出终点
                for (int k = i; k < j; k++) { // 枚举区间内子序列的情况
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]); // 确定区间转移关系
                    // 不断将区间缩小然后推到大区间
                }
            }
        }
        std::cout << dp[1][n] << endl; // 最终结果
    }
private:
    int dp[MAX][MAX];
};
```





**循环区间dp(倍长的思想)**

思想: 将区间变为俩段相同的区间,然后去枚举区间长度,破环成链,

扩展端点的区间dp

[能量项链](https://www.lanqiao.cn/problems/557/learning/?page=1&first_category_id=1&name=%E8%83%BD%E9%87%8F%E9%A1%B9%E9%93%BE)

```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
using ll = long long;
using namespace std;


class Solution {
public: 
    void solve() {
        int n; std::cin >> n;
        std::vector<int> a(n * 2 + 10);
        std::vector<vector<int>>f(n * 2 + 10,vector<int>(n * 2 + 10, 0));
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            a[i + n] = a[i]; // 复制成俩倍
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n * 2; l++) { //环形乘2
                int r = l + len - 1;
                for (int k = l; k < r; k++) {
                    f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, f[i][i + n - 1]);
        }
        std::cout << ans << endl;
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
```







区间dp例题



1. [制作回文串](https://www.lanqiao.cn/problems/1547/learning/?page=1&first_category_id=1&name=制作回文串) 端点的操作

解题: 

```cpp
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//区间dp
// 形成回文串的最小花费
// 枚举回文串长度取最小花费长度的回文串


void solve(){
    int n, m; std::cin >> n >> m;
    string s; std::cin >> s;

    std::vector<int> a(257,0);
    for (int i = 0; i < n ; i++) {
        char t; std::cin >> t;
        int x, y; std::cin >> x >> y;
        a[t - 'a'] = x > y ? y : x;
    }

    vector<vector<int>> f(m,vector<int>(m,0));

    for (int len = 1; len <= m; len++) {
        for (int l = 0; l + len < m; l++) {
            int r = l + len;
            if (s[l] == s[r]) f[l][r] =  f[l + 1][r - 1]; //左右端点相同
            else f[l][r] = std::min(f[l + 1][r] + a[s[l] - 'a'], f[l][r - 1] + a[s[r] - 'a']); // 左右端不相同, 则取删除或者添加的最小值
        }
    }
    std::cout << f[0][m - 1] << endl;
}

int main()
{
    cout.tie(0) -> ios::sync_with_stdio(0);
    cin.tie(0) -> ios::sync_with_stdio(0);
    int T = 1;
    for (int i = 1; i <= T; i++) solve();
    return 0;
}
```



[小飞打地鼠 ](https://www.lanqiao.cn/courses/21967/learning/?id=1338082&compatibility=false)



```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define inf 1'000'000'000
using ll = long long;
using namespace std;


class Solution {
public: 
    void solve() {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (auto &i: a)std::cin >> i;
        std::vector<std::vector<int>> f(n, std::vector<int>(n, -inf)), g(n, std::vector<int>(n, -inf));
        // f: left, g: right
        for (int i = 0; i < n; i++) {
            f[i][i] = g[i][i] = a[i];
        }
        for (int len = 1; len < n; len++) {
            for (int l = 0, r = l + len; r < n; l++, r++) {
                f[l][r] = std::max(g[l + 1][r] - 10 * (r - l) + a[l], f[l + 1][r] - 10 + a[l] / 2);
                g[l][r] = std::max(f[l][r - 1] - 10 * (r - l) + a[r], g[l][r - 1] - 10 + a[r] / 2);
            }
        }
        std::cout << std::max(f[0][n - 1], g[0][n - 1]) << '\n';
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
```





[涂色](https://www.lanqiao.cn/courses/21967/learning/?id=1338084&compatibility=false)



也是区间dp与判断回文串一样判断边界的区间颜色



```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define inf 1'000'000'0
using ll = long long;
using namespace std;


class Solution {
public: 
    void solve() {
        std::string s; std::cin >> s;
        int n = (int)s.size();
        vector<vector<int>>f(n + 10,vector<int>(n + 10,inf));

        for (int i = 0; i < n; i++) f[i][i] = 1; // 这个是单个区间的时候的值

        for (int len = 2; len <= n; len++) {  // 区间dp枚举长度
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (s[l] == s[r]) { // 左右端点相等的时候的值
                    f[l][r] = std::min(f[l + 1][r],f[l][r - 1]);
                } else {
                    for (int k = l; k < r; k++) {
                        f[l][r] = std::min(f[l][r],f[l][k] + f[k + 1][r]); // 左右端点不相等时通过枚举区间控制值
                    }
                }
            }
        }
        std::cout << f[0][n - 1] << endl;
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
```













## 状压dp(抽象)



状压dp一般通过位运算对状态进行压缩减少空间的使用,多个状态合并成一个状态 ,

位运算,





## 数位dp














## 期望dp









# 贪心总结



最优情况的考虑 会涉及到 最大值和最小值, 一般最差的用 sort  > O(n) 

如果要取最大值和最小值可以考虑 priority_queue() (堆)

[最大的卡牌价值 - 蓝桥云课 ](https://www.lanqiao.cn/problems/3250/learning/?page=1&first_category_id=1&name=最大的卡牌价值) : 通过自定义排序找到最优的情况,从部分最优到全局最优



贪心的个人理解: 从自己认为的最优情况即为贪心的解, 将自己最优的想法转换为高级程序语言表达

将个人对贪心的想法总结规律找到相同的规律,然后对此规律进行 翻译



贪心与动态规划的区别 :  贪心它现在的状态不会影响之后的状态, 单个最优情况的合集





## 贪心题型的总结



1. 例如饼干问题 , 当前饼干满足胃口最小,从单个情况考虑推导出整个数组的情况, 
2. 贪心往往会跟区间向关联,通过区间来限定局部最优
3. 贪心还得考虑当前策略是否最优,不同**区间**策略不同, 例如:  [珠宝的最大交替和 - 蓝桥云课 ](https://www.lanqiao.cn/problems/3791/learning/?page=1&first_category_id=1&name=珠宝的最大交替和)    [435. 无重叠区间 - 力扣（LeetCode）](https://leetcode.cn/problems/non-overlapping-intervals/)
4. 贪心的遍历顺序,可能一种遍历方式并不能确定最优情况,还得用其他的方式,从不同的遍历方式中取最优的情况

5. 贪心还得分情况进行讨论 : 贪心的经典题目 钱币找零问题  : [860. 柠檬水找零 - 力扣（LeetCode）](https://leetcode.cn/problems/lemonade-change/description/)  



# 搜索





## 递归

**递归三要素**



**递归输出**



## 深度优先搜索





## 广度优先搜索



![image-20240412012733413](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240412012733413.png)





a



## 回溯算法

![image-20240402165740130](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240402165740130.png)



**N皇后问题**



```cpp
#include<iostream>
using namespace std;

const int N = 12;
int vis[N][N], n, ans;

void dfs(int dep)
{
    // 在这个搜索中dep表示行，i表示列
    // 1 搜索出口
    if(dep == n + 1)
    {
        ans++;
        return;
    }
    // 2 继续搜索
    for(int i = 1; i <= n; ++i)
    {
        // 2.1 排除非法情况
        if(vis[dep][i])
            continue;
        // 2.2 改变状态
        for(int _i = 1; _i <= n; ++_i)
            vis[_i][i]++;
        for(int _i = dep, _j = i; _i >= 1 && _j >= 1; --_i, --_j)
            vis[_i][_j]++;
        for(int _i = dep, _j = i; _i <= n && _j >= 1; ++_i, --_j)
            vis[_i][_j]++;
        for(int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j)
            vis[_i][_j]++;
        for(int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j)
            vis[_i][_j]++;
        // 2.3 下一层
        dfs(dep + 1);
        // 2.4 还原现场
        for(int _i = 1; _i <= n; ++_i)
            vis[_i][i]--;
        for(int _i = dep, _j = i; _i >= 1 && _j >= 1; --_i, --_j)
            vis[_i][_j]--;
        for(int _i = dep, _j = i; _i <= n &&  _j >= 1; ++_i, --_j)
            vis[_i][_j]--;
        for(int _i = dep, _j = i; _i >= 1 && _j <= n; --_i, ++_j)
            vis[_i][_j]--;
        for(int _i = dep, _j = i; _i <= n && _j <= n; ++_i, ++_j)
            vis[_i][_j]--;
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ans << "\n";
    return 0;
}
```





解2



```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 10000
using ll = long long;
using namespace  std;

int ans = 0;

bool isok(vector<vector<int>>& vec,int cow,int row,int n) {
        // 45°
	    for (auto i = row - 1,j = cow - 1; i >= 0 && j >= 0; i--,j--) {
            if (vec[i][j] == 1) {
                return false;
            }
        }
        //135度
        for (auto i = row - 1,j = cow + 1; i >= 0 && j < n;i--,j++) {
            if (vec[i][j] == 1) return false;
        }
        //90度 
        for(auto i = 0;i < row; i++) {
            if(vec[i][cow] == 1) return false;
        }
        return true;
}

void dfs(vector<vector<int>>& a,int m,int n) {
	if(m == n) ans++;
	for(int i = 0; i < n; i++) {
		if(isok(a,i,m,n)) {
			a[m][i] = 1;
			dfs(a,m + 1, n);
			a[m][i] = 0;
		}
	}
}

void solve() {
	int n; std::cin >> n;
	vector<vector<int>> a(n,vector<int>(n,0));
	dfs(a,0,n);
	std::cout << ans << endl; 
}


signed main() {

#if Run
    int _;cin>>_;while(_--) solve();
#else
    solve();
#endif
    return 0;
}
```





[1.小朋友崇拜圈 - 蓝桥云课 (lanqiao.cn)](https://www.lanqiao.cn/problems/182/learning/?page=1&first_category_id=1&problem_id=182)

[1.全球变暖 - 蓝桥云课 (lanqiao.cn)](https://www.lanqiao.cn/problems/178/learning/?page=1&first_category_id=1&name=全球)



## 剪支

![image-20240402183320441](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240402183320441.png)





[1.数字王国之军训排队 - 蓝桥云课 (lanqiao.cn)](https://www.lanqiao.cn/problems/2942/learning/?page=1&first_category_id=1&problem_id=2942)



```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
using ll = long long;
using namespace  std;

const int N = 15;
int n, a[N];
vector<int> v[N]; //v[i]存队伍i中所有人的编号，
                  //比如v[1]存队伍1中所有人的编号

//cnt表示队伍数量，dfs返回在cnt个队伍的情况下是否可以成功分组
bool dfs(int cnt, int x) {
    if (x == n + 1) { //每个人都成功分组
        return true;
    }

    //枚举每个人所属的队伍
    for (int i = 1; i <= cnt; i++) {
        int f = 0;
        for (auto j : v[i]) {
            if (a[x] % j == 0) {
                f = 1;
                break;
            }
        }
        if (f) continue;
        v[i].push_back(a[x]);
        if (dfs(cnt, x + 1)) return true;
        v[i].pop_back(); //恢复现场
    }
    return false;
}
	
void solve() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (dfs(i, 1)) {
            cout << i << endl;
            break;
        }
    }
}

signed main() {

#if Run
   int _;cin>>_;while(_--) solve();
#else
   solve();
#endif
   return 0;
}
```











# 高精度





## 高精度加法

个人理解: 是一种空间转换的方法, 用增加时间来使得空间变化,

高精度算法的原理是模拟竖式计算的方法来增加算法在大数上的运算



```cpp
    void solve() {
        std::string s,t; std::cin >> s >> t;

        std::vector<ll>a(s.size() + 10,0),b(t.size() + 10,0),c(s.size() + t.size(),0);

        for (int i = 0; i < s.size(); i++) a[s.size() - 1 - i] = (s[i] - '0');
        for (int i = 0; i < t.size(); i++) b[t.size() - 1 - i] = (t[i] - '0');

        int len = s.size() > t.size() ? s.size() : t.size();
        
        for (int i = 0; i < len; i++) {
            c[i] = a[i] + b[i];
        }

        for (int i = 0; i < len; i++) {
            if(c[i] >= 10) {
                c[i + 1] = c[i + 1] + c[i] / 10;
                c[i] %= 10;
            }
        }
        if(c[len] != 0) len++;
        for (int i = len - 1; i >= 0; i --) {
            std::cout << c[i];
        }
    }
```





## 高精度减法



```cpp
    void solve() {
        std::string s,t; std::cin >> s >> t;
        std::string flag = "+";

        std::vector<ll>a(s.size() + 10,0),b(t.size() + 10,0),c(s.size() + t.size(),0);

        if (s.size() < t.size() || s.size() == t.size() && s < t) {
            std::swap(s,t);// 默认 s > t
            flag = "-";
        }

        for (int i = 0; i < s.size(); i++) a[s.size() - 1 - i] = (s[i] - '0');
        for (int i = 0; i < t.size(); i++) b[t.size() - 1 - i] = (t[i] - '0');


        for (int i = 0; i < s.size(); i++) {
            c[i] = a[i] - b[i];
        }

        for (int i = 0; i < t.size(); i++) {
            if (c[i] < 0) {
                c[i + 1] -= 1;
                c[i] += 10;
            }
        }
        int index = 0;
        for (int i = s.size() - 1; i >= 0; i --) {
            if(c[i] != 0) {
                index = i;
                break;
            }
        }
        if (flag == "-") std::cout << "-";
        for (int i = index; i >= 0; i --) {
            std::cout << c[i];
        }
    }
```





## 高精度乘法



```cpp
char a1[10001], b1[10001];
int a[10001], b[10001], i, x, len, j, c[10001];
int main () {
    cin >> a1 >> b1; //不解释，不懂看前面
    int lena = strlen(a1); //每个部分都很清楚
    int lenb = strlen(b1); //这只是方便你们复制
    
    for (i = 1; i <= lena; i++)
    	a[i] = a1[lena - i] - '0';//倒序存储
    for (i = 1; i <= lenb; i++)
    	b[i] = b1[lenb - i] - '0';//倒序存储
    
    for (i = 1; i <= lenb; i++)
    	for (j = 1; j <= lena; j++)
    		c[i + j - 1] += a[j] * b[i];//存每位答案
    
    for (i = 1; i < lena + lenb; i++)
        if (c[i] > 9) {
        c[i + 1] += c[i] / 10;//进位
        c[i] %= 10;//取当前位答案
    	}
    
    len = lena + lenb;
    while (c[len] == 0 && len > 1)//去除前导零
    	len--;
    for (i = len; i >= 1; i--)//输出答案
    	cout << c[i];
    return 0;
}
```





# 哈希表

哈希表是用元素来当数组下标去索引值的一种方法,主要是用来管理值排序等操作



## 一、什么是Hash表

要想知道什么是哈希表，那得先了解哈希函数
哈希函数
对比之前博客讨论的二叉排序树 二叉平衡树 红黑树 B B+树，它们的查找都是先从根节点进行查找，从节点取出数据或索引与查找值进行比较。那么，有没有一种函数H，根据这个函数和查找关键字key，可以直接确定查找值所在位置，而不需要一个个比较。这样就**“预先知道”**key所在的位置，直接找到数据，提升效率。
即
地址index=H（key）
说白了，hash函数就是根据key计算出应该存储地址的位置，而哈希表是基于哈希函数建立的一种查找表



## 二、哈希函数的构造方法

根据前人经验，统计出如下几种常用hash函数的构造方法：
**直接定制法**

哈希函数为关键字的线性函数如 H（key）=a*key+b
这种构造方法比较简便，均匀，但是有很大限制，仅限于地址大小=关键字集合的情况

**使用举例：**

假设需要统计中国人口的年龄分布，以10为最小单元。今年是2018年，那么10岁以内的分布在2008-2018，20岁以内的分布在1998-2008……假设2018代表2018-2008直接的数据，那么关键字应该是2018，2008，1998……
那么可以构造哈希函数H（key）=（2018-key）/10=201-key/10

------------------------------------------------





# 模拟



小红想让你构造一个长度为 *n* 的数组，满足以下俩个条件：

1. 该数组最大值不超过 *k*。
2. 数组所有数之和等于 *x*。



**样例**

输入

```txt
4 6 15
```

输出

```txt
1 3 6 5
```



代码

```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 10000
using ll = long long;
using namespace  std;

// 问题1,怎么样构造数组?
// 问题2,从哪里选择数
// 用dfs枚举所有情况 将每个数的每个情况列举 -> 一定超时
// 数据的和等于 x
// 因为数据有多个所以可以用数学的方法

void solve() {
    ll n, k, x; std::cin >> n >> k >> x;
    int a[n + 5];
    if(x / k > n) {
        std::cout << -1 << endl;
        return ;
    } else if(x % k == 0 && x / k == n){
        for(int i = 0; i < x / k; i++) std::cout << k << " ";
        std::cout << endl;
    } else {
        if(x / n > k) {
            std::cout << -1;
            return ;
        }
        for(int i = 0; i < n; i++) {
            a[i] = x / n;
        }
        int tmp = x % n;
        int t = 0;
        while(tmp) {
            if(tmp >= (k - a[t])) {
                tmp = tmp - (k - a[t]);
                a[t] = k;
            } else {
                a[t] = a[t] + tmp;
                tmp = 0;
            }
            t++;
            if(t > n) {
                std::cout << -1 << endl;
                return ;
            }
        }
        for(int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << endl;
    }
    
}

signed main() {

#if Run
    int _;cin>>_;while(_--) solve();
#else
    solve();
#endif
    return 0;
}
```



进阶: 额外满足一个条件: 该数组所有数都不相同。



**代码**







# 字符串

![image-20240412003237533](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240412003237533.png)



```
s.substr(起点, 终点);
s.substr(起点);//从起点开始到最后
```



## 最长递增子序列

[最长上升子序列 (LIS) 详解+例题模板 (全)](https://blog.csdn.net/lxt_Lucia/article/details/81206439)



```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 103, INF = 0x7f7f7f7f;
int a[maxn], f[maxn];
int n,ans = -INF;
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) 
    {
        scanf("%d", &a[i]);
        f[i] = 1;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<i; j++)
            if(a[j] < a[i])
                f[i] = max(f[i], f[j]+1);
    for(int i=1; i<=n; i++) 
        ans = max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}
```





## 最大递增子序列

[最大花之能量 - 蓝桥云课](https://www.lanqiao.cn/problems/3967/learning/)

状态转移方程：通过遍历数组 a[] 中的每个元素 a[i]，并与之前的元素 a[j] (j < i) 进行比较。如果 a[i] 大于 a[j]，意味着可以将 a[i] 加入到以 a[j] 结尾的子序列中，从而得到以 a[i] 结尾的子序列。此时，更新 b[i] 为 b[j] + a[i]，即将以 a[i] 结尾的子序列的最大和加上 a[j]。这样可以保证 b[i] 记录的是以 a[i] 结尾的子序列的最大和。



```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
using ll = long long;
using namespace  std;

void solve() {
    int n; 
    cin >> n;
    vector<ll> a(n); 
    for (auto &x : a) cin >> x;
    
    vector<ll> dp = a; // dp数组，dp[i]表示以a[i]结尾的最大子序列和
    dp[0] = a[0];
    ll ans = dp[0]; // 记录最大的子序列和
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]); // 更新dp[i]
            }
        }
    }
    ans = *max_element(dp.begin(),dp.end());
    std::cout << ans << endl;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    
    return 0;
}
```







## KMP算法

计算next 数组 (next 数组仅与 模式串 p 有关) 的方式就是用P自己去匹配自己

```cpp
char s[M], p[M];

int next[M];

int n = strlen(s + 1), m = strlen(p + 1); // 字符串下标从 1 开始

next[0] = next[1] = 0;
for (int i = 2, j = 0; i <= m; ++i) 
{
    // 不断匹配 p[i] 和 p[j + 1]
    while(j && p[i] != p[j + 1]) j = next[j];
    if (p[i] == p[j + 1]) j++; // 从 while 出来后要么 j = 0 要么 p[i] == p[j + 1] 如果匹配成功 则 j 后移
    next[i] = j; // 如果i 匹配失败 就回到 j 因此 p[1 ~ j] = p[i - j + 1 ~ i] 或者 j = 0
}
```



通过next数组匹配

```cpp
for (int i = 1, j = 0; i <= n; i++) 
{
    while(j && s[i] != p[j + 1]) j = next[j];
    if(s[i] == p[i + 1]) j++;
    if (j == m) //成功匹配
}
```



例题: [1.斤斤计较的小Z - 蓝桥云课 ](https://www.lanqiao.cn/problems/2047/learning/?page=1&first_category_id=1&problem_id=2047)



```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char p[N],s[N];
int nex[N];
int main()
{
    cin>>p+1;int m=strlen(p+1);//p+1表示匹配时从下标1开始
    cin>>s+1;int n=strlen(s+1);
    nex[0]=nex[1]=0;//将它们初始化为0
    for(int i=2,j=0;i<=m;i++)//因为一开始p++，所以i=2，j=0
    {
        while(j&&p[i]!=p[j+1]) j=nex[j];//将p[i]与p[j+1]进行比较，如果能进入循环，此时不匹配，然后将j跳到nex[j]（表示与当前后缀相等的前缀的末尾）
        if(p[i]==p[j+1]) j++;//（相等，则继续往下判断）
        nex[i]=j;//表示此时前后缀相等的个数
    }
    int ans=0;
    for(int i=1,j=0;i<=n;i++)//这里i不是等于2，是因为上面是p数组自己内部进行比较，而下面是s数组和p数组进行，不需要错开2，错开1就行，因为是i和j+1进行比较
    {
        while(j&&s[i]!=p[j+1]) j=nex[j];
        if(s[i]==p[j+1]) j++;
        if(j==m) ans++;//如果等于，说明找到符合p字符串的一个地方
    }
    cout<<ans << endl;
    return 0;
}
```



## 字符串哈希









## Manacher算法



模版

[P3805 【模板】manacher - 洛谷 | 计算机科学教育新生态 ](https://www.luogu.com.cn/problem/P3805)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=11000000+5;
const int inf=2147483647;

int cnt, len, ans = 0;
char s[N], ss[N*2];
int p[N*2];

void init(){//将每两个字符中插入一个字符
    len = strlen(s), cnt = 1;
    ss[0] = '!'; ss[cnt] = '#';
    for(int i=0;i<len;i++)
	ss[++cnt] = s[i], ss[++cnt] = '#';
}

void manacher(){
    int pos = 0, mx = 0;
    for(int i=1;i<=cnt;i++){
		if(i < mx) p[i] = min(p[pos*2-i],mx-i);
		else p[i] = 1;
		while(ss[i+p[i]] == ss[i-p[i]]) p[i]++;
		if(mx < i+p[i]) mx = i+p[i], pos = i;
		ans = max(ans,p[i]-1);
    }
}

int main(){
    scanf("%s",s);
    init(); manacher();
    printf("%d\n",ans);
    return 0;
}
```



## 字典树



![image-20240406125020071](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240406125020071.png)

insert 函数





将字符串插入到 Trie 中



![image-20240406134238790](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240406134238790.png)



判断某字符串在 Trie 中的出现次数 

![image-20240406134308008](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240406134308008.png)



[2.前缀判定 - 蓝桥云课 ](https://www.lanqiao.cn/problems/1204/learning/?page=1&first_category_id=1&name=前缀判)



模版

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2E6 + 5;

int nex[N][26];
int cnt[N];
int idx = 2;

void insert(char s[])
{
    int x = 1;
    for (int i = 0; s[i]; i++)
    {
        // 判断x是否存在s这条边
        if (!nex[x][s[i] - 'a'])
            nex[x][s[i] - 'a'] = idx++;
        x = nex[x][s[i] - 'a'];
    }
    cnt[x]++;
}

bool check(char s[])
{
    int x = 1;
    for (int i = 0; s[i]; i++)
    {
        x = nex[x][s[i] - 'a'];
    }
    return x != 0;
}

int main()
{
    ios::sync_with_stdio, cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char s[N];
        cin >> s;
        insert(s);
    }
    for (int i = 1; i <= m; i++)
    {
        char s[N];
        cin >> s;
        cout << (check(s) ? 'Y' : 'N') << endl;
    }
    return 0;
}
```





## 01字典树



01 - trie 树主要解决二进制上的问题, 



题目



给定 n 个数, 求 $$ a_i$$ xor $$a_j$$  最大值 $$(n <= 2^4 , a_i <= 10^9)$$ 



**输入**

```
4
121 321 232434 2324
```

**输出**

```
232434
```





```cpp
#include <bits/stdc++.h>
using namespace std;
#define maxn 210000
int a[maxn],ch[maxn][2], val[maxn], n, ans, tot;

void insert(int x) {
    int now = 0;
    for (int j = 31; j >= 0; j--) {
        int pos = ((x >> j) & 1);
        if (!ch[now][pos]) ch[now][pos] = ++tot;
        now = ch[now][pos];
    }
    val[now] = x;
    return ;
}

int query(int x) {
    int now = 0;
    for (int j = 31; j >= 0; j--) {
        int pos = ((x >> j) & 1);
        if (ch[now][pos ^ 1]) now = ch[now][pos ^ 1];
        else now = ch[now][pos];
    }
    return val[now];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, a[i]; std::cin >> x;
        insert(x);
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, query(a[i]));
    }
    cout << ans << endl;
    return 0;
}
```





# 数学



## 矩阵乘法



[1.矩阵相乘 - 蓝桥云课](https://www.lanqiao.cn/problems/1550/learning/?page=1&first_category_id=1&name=矩阵相乘)

```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define FOR(i, j, k) for(int i(j); i <= (k); ++i)
#define ROF(i, j, k) for(int i(j); i >= (k); --i)
#define pii std::pair<int,int>
#define pll std::pair<ll, 1l>
#define ALL(v) (v).begin(),(v).end()
using namespace std;
using ll = long long;


void solve() {
    int N,M,K; std::cin >> N >> M >> K;
    std::vector<std::vector<ll>> a(N,std::vector<ll>(M)) , b(M,std::vector<ll>(K));
    std::vector<vector<ll>> c(N,vector<ll>(K));

    for (auto &x : a) for(auto &y : x) std::cin >> y;
    for (auto &x : b) for(auto &y : x) std::cin >> y;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            ll tmp = 0;
            for(int k = 0; k  < M; k++) {
//                ll A = a[N][k], B = b[k][K]; // 这里小心越界了
                ll A = a[i][k], B = b[k][j];
                tmp  = tmp + A*B;
            }
            c[i][j] = tmp;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            std::cout << c[i][j] << " \n"[j == K - 1];
        }
    }
}

signed main() {
    std::cin.tie(0) -> std::ios::sync_with_stdio(false);
    std::cout.tie(0) -> std::ios::sync_with_stdio(false);

#if Run
    int _;std::cin>>_;while(_--) solve();
#else
    solve();
#endif
    return 0;
}
```



## 组合



先用map统计出不同的数字的个数，然后不同的数字肯定至多选一个就可以了，然后每种数字就是选和不选两种状态，比如说122+（为了区分两个2）4，1有一个，2有两个，4有一个，所以1有两种选择（不选/选1），2有三种选择（选2/选2+/不选），4有两种选择（选4/不选)所以将每个数字的数量相乘之后，减去全不选的那一种情况就可以了(记得mod)



```cpp
#include <bits/stdc++.h>

#define endl '\n'
#define x first
#define y second
#define pb push_back
#define all(a) a+1,a+n+1
#define allv(a) a.begin(),a.end()
#define IOSCC ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int a[N];
int dp[N][N];
int n;
map<ll,ll> mp;

void solve() {
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        ll t;
        cin >> t;
        mp[t]++;
    }
    
    ll res = 1;
    for(auto m : mp){
        res = (res * (m.second + 1)) % mod;
    }

    cout<<res % mod - 1;
}

int main() {
    IOSCC;
    int _ = 1;
//    cin >> _;

    while (_--) {
        solve();
        cout << endl;
    }

    return 0;
}
```





## 整除

![image-20240406211859418](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240406211859418.png)

C++默认向下取整, 怎么样向上取整?



**<font color="red">计算 x / y 向上取整, 需将式子改写为 $(x + y - 1) / y$ 或者 $(x - 1) / y + 1$ </font>**

![image-20240406212340448](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240406212340448.png)



## 同余

同余是数论中非常重要的概念，意思是两个或多个数字x，对于一个模数M的余数是相等的，或者说在模M意义下，他们是相等的。

例如当M=7，x=[1,8,15,8,50]是同余的，这些x有一个共同的关系，就是x%M=1。



![image-20240406213241859](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240406213241859.png)



## GCD 和 LCM

C++内置函数 `__gcd(a,b)` , `lcm(a,b)`;



**gcd(int a,int b)**



![image-20240406213737674](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240406213737674.png)

**lcm(int a, int b)**

![image-20240406213948675](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240406213948675.png)

俩俩的最大公倍数与求数组的最大公约数即数组的的最大公约数



## 高斯消元





## 裴蜀定理



裴蜀定理说明了对任何整数a、b和它们的最大公约数d，关于未知数x和y的线性不定方程（称为裴蜀等式）的性质。具体地说，如果a和b是整数，且它们的最大公约数是d，那么对于任意的整数x和y，ax+by一定是d的倍数。特别地，一定存在整数x和y，使得ax+by=d成立。



a , b 为全不为 0 的整数 , 则存在整数 x, y 使得   $$ax + by = gcd(a , b)$$





![image-20240229132915151](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240229132915151.png)



## 秦九韶算法





## 卡特兰数





# 数据结构



## 栈



经典例题



**后缀表达式**

```cpp
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

typedef int elemtype;

typedef struct {
    elemtype data[MAX];
    int top;
}S;

void Init(S **s){
    *s = new S;//要创建一个栈
    (*s)->top=-1;//初始化栈
}

int Push(S*s,elemtype x){//入栈
    if(s->top == MAX-1)//到栈顶
        return 0;
    else{
        // s->top++;//栈中top定位加1
        s->data[++(s->top)] = x;//将x的值存储在栈顶
        return 1;
    }
}

int Emptystack(S*s){//判断栈是否为空
    return s->top == -1;
}

int pop(S *s,elemtype*x){//输入的是地址
    if(Emptystack(s)){
        return 0;
    }else{
        *x = s->data[(s->top)--];
        return 1;
    }
}

elemtype Gettop(const S* s){//取栈顶元素
    if(s->top==-1){//到底部
        return 1;
    }
    else{
        return s->data[s->top];
    }
}


int main(){
    char s[10];//直接转字符串
    S*p;//定义栈名
    Init(&p);//创建栈
    char*q= &s[0];
    while(scanf("%s",q)!=EOF){
        if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'){
            int num1,num2;
            pop(p,&num2);//出栈将栈顶元素存储在num2中
            pop(p,&num1);//将下一元素存储在num1中
            switch(s[0]){
            case '+':
                Push(p, num1 + num2);
                break;
            case '-':
                Push(p, num1 - num2);
                break;
            case '*':
                Push(p, num1 * num2);
                break;
            case '/':
               Push(p, num1 / num2);
                break;
            }
        }else{//不满足运算符
            Push(p,atoi(s));//入栈
        }//不断循环最后剩下结果
    }
    int num=0;
    pop(p,&num);
    cout<<num;//输出结果
    delete p;//释放空间
    return 0;
}
```





# 图论



## dsu on tree



## 分层图





## LCA 



```cpp
#include <cstdio>
#include <cstring>
#include <vector>

#define MXN 40005
using namespace std;
std::vector<int> v[MXN];
std::vector<int> w[MXN];

int fa[MXN][31], cost[MXN][31], dep[MXN];
int n, m;
int a, b, c;

// dfs，用来为 lca 算法做准备。接受两个参数：dfs 起始节点和它的父亲节点。
void dfs(int root, int fno) {
  // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1。
  fa[root][0] = fno;
  dep[root] = dep[fa[root][0]] + 1;
  // 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
  // 2^(i-1) 的祖先节点。
  for (int i = 1; i < 31; ++i) {
    fa[root][i] = fa[fa[root][i - 1]][i - 1];
    cost[root][i] = cost[fa[root][i - 1]][i - 1] + cost[root][i - 1];
  }
  // 遍历子节点来进行 dfs。
  int sz = v[root].size();
  for (int i = 0; i < sz; ++i) {
    if (v[root][i] == fno) continue;
    cost[v[root][i]][0] = w[root][i];
    dfs(v[root][i], root);
  }
}

// lca。用倍增算法算取 x 和 y 的 lca 节点。
int lca(int x, int y) {
  // 令 y 比 x 深。
  if (dep[x] > dep[y]) swap(x, y);
  // 令 y 和 x 在一个深度。
  int tmp = dep[y] - dep[x], ans = 0;
  for (int j = 0; tmp; ++j, tmp >>= 1)
    if (tmp & 1) ans += cost[y][j], y = fa[y][j];
  // 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先。
  if (y == x) return ans;
  // 不然的话，找到第一个不是它们祖先的两个点。
  for (int j = 30; j >= 0 && y != x; --j) {
    if (fa[x][j] != fa[y][j]) {
      ans += cost[x][j] + cost[y][j];
      x = fa[x][j];
      y = fa[y][j];
    }
  }
  // 返回结果。
  ans += cost[x][0] + cost[y][0];
  return ans;
}

void Solve() {
  // 初始化表示祖先的数组 fa，代价 cost 和深度 dep。
  memset(fa, 0, sizeof(fa));
  memset(cost, 0, sizeof(cost));
  memset(dep, 0, sizeof(dep));
  // 读入树：节点数一共有 n 个，查询 m 次，每一次查找两个节点的 lca 点。
  scanf("%d %d", &n, &m);
  // 初始化树边和边权
  for (int i = 1; i <= n; ++i) {
    v[i].clear();
    w[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d %d %d", &a, &b, &c);
    v[a].push_back(b);
    v[b].push_back(a);
    w[a].push_back(c);
    w[b].push_back(c);
  }
  // 为了计算 lca 而使用 dfs。
  dfs(1, 0);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a, &b);
    printf("%d\n", lca(a, b));
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) Solve();
  return 0;
}
```







## 树的查询



```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> tree[MAXN]; // 二维数组 先设置了长度
int depth[MAXN];  // 这个用于记录深度

// 计算以节点 u 为根的子树的深度
void calculateDepth(int u, int parent) {
    for (int v : tree[u]) {
        if (v != parent) {
            depth[v] = depth[u] + 1;
            calculateDepth(v, u);
        }
    }
}

// 计算以节点 u 为根的子树的直径
int calculateDiameter(int u) {
    int maxDepth = 0;
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        maxDepth = max(maxDepth, depth[node]);

        for (int v : tree[node]) {
            q.push(v);
        }
    }
    
    return maxDepth;
}

int main() {
    std::cin.tie(0) -> std::ios::sync_with_stdio(false);
    std::cout.tie(0) -> std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    depth[1] = 0;
    calculateDepth(1, 0);

    while (m--) {
        int op, i;
        cin >> op >> i;

        if (op == 1) {
            // 删除第 i 号节点及其子树
            depth[i] = 0; // 将深度置为 0，表示节点已删除
        } else {
            // 查询第 i 号节点子树的直径
            if (depth[i] != 0) {
                int diameter = calculateDiameter(i);
                cout << diameter << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
```







## 并查集



并查集是什么

并查集，是一种判断“远房亲戚”的算法。

打个比方：你身边的某个“朋友”，很有可能就是你父亲的母亲的姑妈的大姨的哥哥的表妹的孙子的女儿的父亲的孙子。如果给定这么一张“家谱”（无向图），如何判断两个顶点是不是“亲戚”呢？用人话说，就是判断一个图中两个点是否联通（两个顶点相互联通则为亲戚）。

并查集是专门用来解决这样的问题的，和搜索不同，并查集在构建图的时候同时就标记出了哪个“人”属于哪个“团伙”（一团伙中的点两两联通）。

![1](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9tbWJpei5xcGljLmNuL21tYml6X3BuZy9OdE81c2lhbEpaR3BXeHFxU2t4NHIxUlpVWWljaWF1bjJkbVdIMTU5ZmUzcGR3ZEppY2dnQW9ucXd3dmNUTUJpYU93RkhDQkVIYmpFOFRESGdlS3FsUEwzNW5BLzY0MA?x-oss-process=image/format,png)







```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
using unl = __int128_t;

const int N = 1e5 + 9;

class Solution {
public: 
     void solve() {
       int n,q; std::cin >> n >> q;

       for (int i = 1; i <= n; ++ i) pre[i] = i,siz[i] = i;

       while(q --> 0) {
            int op; std::cin >> op;//这个是操作方式
            if (op == 1) {
                int x,y; std::cin >> x >> y;
                merger(x,y); // 函数确认x y的连通性
            } else if (op == 2) undo();
            else {
                int x,y; std::cin >> x >> y;
                std::cout << (root(x) == root(y) ? "YES" : "NO") << "\n";
            }
       }
    }
public: //找到这个点的根是多少
    int root(int x) {
        return pre[x] == x ? x : root(pre[x]); //如果没有找到则找父根
    }
public://合并操作都在根上
    void merger(int x,int y) {
        int rx = root(x),ry = root(y);
        if (rx == ry) return ;

        if (siz[rx] > siz[ry]) std::swap(rx,ry);

        stk[++ top] = {rx, ry};

        pre[rx] = ry;

        siz[ry] += siz[rx];
    }
public:
    void undo() {
        if (!top) return;
        auto [x, y] = stk[top --];

        pre[x] = x;
        siz[y] -= siz[x];
    }
private:
    int pre[N],siz[N],top;
    std::pair<int,int> stk[N];
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

```





## 最小生成树(MST)

一个图中可能存在多条相连的边,我们**一定可以从一个图中挑出一些边生成一棵树。**这仅仅是生成一棵树,还未满足最小,

**当图中每条边都存在权重时,这时候我们从图中生成一棵树(n - 1 条边)时,生成这棵树的总代价就是每条边的权重相加之和。** 

即包含每个结点但是他们最后的权值之和最小的情况



> <font color= "red">**一个有N个点的图，边一定是大于等于N-1条的。图的最小生成树，就是在这些边中选择N-1条出来，连接所有的N个点。这N-1条边的边权之和是所有方案中最小的。**</font>



*最小生成树的性质: 1. MST的边权和是所有生成树中最小的。 2. MST 的最大边权是所有生成树中最小的*



**实现最小生成树的两种算法**

1. prim算法
2. Kruskal算法



例题 : [最小生成树 ](https://ac.nowcoder.com/acm/problem/19795)

`贪心`

```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
using ll = long long;
using namespace  std;

//贪心
void solve()
{
    ll n; std::cin >> n; // n 为点 , m为边
    std::vector<ll> b(n + 10,0);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
        ans += b[i];
    }
    sort(b.begin() ,b.begin() + n);
    ans += (n - 2) * b[0];
    std::cout << ans << endl;
}


signed main() {

    cin.tie(0) -> ios::sync_with_stdio(0);
    cout.tie(0) -> ios::sync_with_stdio(0);

#if Run
    int _;cin>>_;while(_--) solve();
#else
    solve();
#endif

    return 0;
}
```





###  **prim算法**

![image-20240408003838628](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240408003838628.png)



![image-20240408003851154](C:\Users\NWT\AppData\Roaming\Typora\typora-user-images\image-20240408003851154.png)

模版题 : [1.旅行销售员 - 蓝桥云课 ](https://www.lanqiao.cn/problems/3322/learning/?page=1&first_category_id=1&problem_id=3322)



```cpp
#include<bits/stdc++.h>
#define Run 1
#define endl "\n"
#define inf 0x3f3f3f3f
#define FOR(i, j, k) for(int i(j); i <= (k); ++i)
#define ROF(i, j, k) for(int i(j); i >= (k); --i)
#define pii std::pair<int,int>
#define pll std::pair<ll, 1l>
#define ALL(v) (v).begin(),(v).end()
#define Ese(ans) ans.erase(unique(ALL(ans)), ans.end())
using namespace std;
using ll = long long;


const int N = 1e5 + 5;

struct edge{
    int y,w;
    bool operator < (const edge& u) const{
        return w > u.w;
    }
};

int n,m;
vector<edge> g[N];

int prim()
{
    int res = 0;
    vector<int> d(N,inf),vis(N,0); 
    priority_queue<edge> pq;
    
    
    pq.push({1,d[1] = 0});
    while(!pq.empty()){
        auto edge = pq.top();// 第一个结点的边
        int x = edge.y;
        pq.pop();
        
        if(vis[x]) continue; // 判断是否使用过这条边
        vis[x] = true;
        
        res = max(res,d[x]);
        
        for(auto edge : g[x]){
            int y = edge.y,w = edge.w;
            if(w < d[y]) pq.push({y,d[y] = w}); //先赋值然后再传值 相当 d[y] = w , push({y, d[y]})的顺序
        }
        
    }
    return res;
}

void solve()
{
    for(int i = 1;i <= n;i ++) g[i].clear();
    cin >> n >> m; // m 为边数 n 为结点数
    while(m --){
        int x,y,w;
        cin >> x >> y >> w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    
    cout << prim() << endl;
}

signed main() {
    std::cin.tie(0) -> std::ios::sync_with_stdio(false);
    std::cout.tie(0) -> std::ios::sync_with_stdio(false);
    
#if Run
    int _;std::cin>>_;while(_--) solve();
#else
    solve();
#endif
    return 0;
}

```









### **Kruskal算法**

Kruskal 算法是基于贪心的想法实现

步骤

1. 将所有的边按照边权排序
2. 从小到大遍历所有边 (u,v), 如果 (u,v) 已经联通就跳过, 否则就选中 (u,v) , 将它俩连接 (并查集)



模版题 : [1.旅行销售员 - 蓝桥云课 ](https://www.lanqiao.cn/problems/3322/learning/?page=1&first_category_id=1&problem_id=3322)

```cpp
#include<bits/stdc++.h>
#define Run 1
#define endl "\n"
#define N 100005
using ll = long long;
using namespace  std;


struct Edge // 用于存储边
{
    int x, y, c;
    /* 自定义排序规则 */
    bool operator < (const Edge &u) const
    {
        return c < u.c; // 边权按照升序排序
    };
};

int pre[N];
int root(int x) {return pre[x] = (pre[x] == x ? x : root(pre[x]));}

void solve()
{
    int n, m; std::cin >> n >> m;
    std::vector<Edge> es;

    // 存下所有数据
    for (int i = 1; i <= m; i++)
    {
        int x, y, c; std::cin >> x >> y >> c;
        es.push_back({x,y,c});
    }
    // 排序
    std::sort(es.begin(),es.end());
    // 并查集的初始化,判断边是否相连
    for (int i = 1; i <= n; ++i) pre[i] = i;

    int ans = 0;
    for (const auto & [x, y, c] : es)
    {
        /* 判断俩边是否相连 */
        if(root(x) == root(y)) continue;
        /*不相连*/
        ans = std::max(ans, c);
        pre[root(x)] = root(y); // 修改bug的地方
    }
    std::cout << ans << endl;
}


signed main() {

    cin.tie(0) -> ios::sync_with_stdio(0);
    cout.tie(0) -> ios::sync_with_stdio(0);

#if Run
    int _;cin>>_;while(_--) solve();
#else
    solve();
#endif

    return 0;
}
```



**无向图的边的求法**

如果你知道图的点数为$n$个，但没有给出完整的图，你可以根据不同类型的图使用不同的方法来计算边数。以下是一些常见类型的图的边数计算方法：

1. **无向完全图**：在无向完全图中，每对不同的顶点都有一条边连接。因此，对于$n$个顶点的无向完全图，边数可以通过组合学的方法计算得到，公式为$E = \frac{n(n-1)}{2}$，其中$E$表示边数。

2. **有向完全图**：在有向完全图中，每对不同的顶点之间都有两条边（一个方向的两条边）。因此，对于$n$个顶点的有向完全图，边数可以通过计算顶点对的数量，公式为$E = n(n-1)$。

3. **一般图**：对于一般图，边的数量是不确定的，因为可以有任意数量的边。通常，你需要已知的信息或者图的具体结构来计算边数。

请根据你所面对的图的类型选择相应的计算方法。









# 总结篇



[蓝桥杯救命总结讲解](https://www.bilibili.com/video/BV1YZ421h7Ry?p=1)



1. [大石头的搬运工](https://www.lanqiao.cn/courses/21967/learning/?id=1337916&compatibility=false) : 考试时如果不会数学推理就模拟

2. [1.最大数组和 ](https://www.lanqiao.cn/problems/3260/learning/?page=1&first_category_id=1&name=最大数组和) : 

```
宏观解题
1. 多组读入数据
2. 比较最小俩值的大小是否大于最大值
3. 大于最大则删除最大 否则删除最小
最后输出答案
```

3. [四元组问题]([1.四元组问题 - 蓝桥云课 (lanqiao.cn)](https://www.lanqiao.cn/problems/3416/learning/?page=1&first_category_id=1&name=四元组问题))



```cpp
#include <bits/stdc++.h>

using LL = long long;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a)std::cin >> x;
    std::vector<int> pre(n, -inf - 1), suf(n);
    int mn = inf + 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > mn) {
            pre[i] = a[i];
        }
        mn = std::min(mn, a[i]);
    }
    mn = inf + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > mn) {
            suf[i] = 1;
        }
        mn = std::min(mn, a[i]);
    }
    for (int i = 1; i < n; i++)pre[i] = std::max(pre[i - 1], pre[i]);
    for (int i = 1; i < n - 1; i++) {
        if (pre[i] > a[i + 1] && suf[i + 1]) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    for (int i = 1; i <= T; i++)solve(i);
    return 0;
}
```



前缀和与差分

[肖恩的投球游戏](https://www.lanqiao.cn/courses/21967/learning/?id=1337921&compatibility=false)



差分对区间进行操作, 单独建立一个数组去求差分结果, 然后对数组做前缀和,最后将数组值相加即区间操作的值



```cpp
#include<bits/stdc++.h>
#define Run 0
#define endl "\n"
#define N 100005
using unl = __int128_t;
using namespace std;
using ll = long long;

//解题思路:  l 框 投 c 个球 

class Solution {
public: 
    void solve() {
        ll n,q; std::cin >> n >> q;
        std::vector<ll>a(n + 5);
        for (int i = 1; i <= n; i++) std::cin >> a[i];
        std::vector<ll>b(n + 5);
        while(q--) {
            ll l,r,c; std::cin >> l >> r >> c;
            b[l] += c,b[r + 1] -= c;
        }
        for (int i = 1; i <= n; i++) b[i] += b[i - 1];
        for (int i = 1; i <= n; i++) std::cout << a[i] + b[i] << " ";
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
```





#### **二维差分**

#### **双指针**








  # 目前进度

  

  1.五大基础算法

  - 贪心算法
  - 动态规划
  - 分治
  - 回溯
  - 枚举

  

  大模块

    1. 数论
    2. 图论

  

  小算法

    1. 二分
    2. 快速幂
    3. 高精度算法
    4. 日期问题
    5. 进制转换
    6. 优先队列的运用
    7. 双指针
    8. 素数判断
    9. gcd() , exgcd();
    10. 

  

  - 贪心算法

    1. 零钱找零
    2. 珠宝~
    3. 分组~

  贪心算法没有模板全是经验

  

  - 动态规划

    1. 线性dp
    2. 背包问题
    3. 区间dp
    4. 路径查找

  

  - 回溯算法 (DFS)

    1. 组合问题
    2. N皇后问题
    3. 数字王国之军训排队(剪支)

  

  

  - 模拟
