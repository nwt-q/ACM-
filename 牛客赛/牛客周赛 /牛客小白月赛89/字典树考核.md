##[字典树考核](https://www.lanqiao.cn/problems/17166/learning/)

> 题解:
> 举个例子
```
3
1 2 3
```
将三位数转换为二进制表示
```
0000001
0000010
0000011
```
每一位三取俩数进行组合,如果满足条件则统计数 `ans++` 



```cpp
#include <iostream>
using namespace std;
#define int long long
int n;
const int N=1e6;
int er[32];     //储存二进制的位置1的个数
int a[N];

void p(int x) {
    for (int i = 0; i < 32; ++i) {
        int bit = (x & (1 << i)) >> i;
        if(bit==1)
        {
            er[i]++;
        }
    }
}

/**
 * 主函数
 * 无参数输入
 * 返回值: 程序执行结果，此处未使用
 */
void solve() {
    // 读取变量n的值
    cin>>n;
    // 遍历1到n，读取并处理每个输入的数值
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p(a[i]); // 对每个读取的数值进行某种处理，具体功能未定义
    }
    int res=0;
    // 遍历0到31，计算每个数值出现的次数大于1的情况下的组合数，并累加到res
    for(int i=0;i<=31;i++)
    {
        if(er[i]>1)
        {
            int qwe=er[i];
            // 计算当前数值i出现次数（qwe）的组合数（C(qwe, 2)），即从qwe个相同元素中选取2个元素的组合数，并将结果累加到总和res中
            res+=(qwe*(qwe-1))/2;
        }
    }

    cout<<res; // 输出结果
}


signed main()
{
    int T = 1; 
    for(int i = 1; i <= T; i++) solve();
    return 0;
}
```
