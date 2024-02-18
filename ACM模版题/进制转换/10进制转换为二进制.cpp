#include<bits/stdc++.h>
#include <bitset>
#define Run 0
#define endl "\n"
#define N 100005
using unl = __int128_t;
using ll = long long;
using namespace  std;
char str_[1005][105];
char str[1005][105];

//bitset<32> 去除前导0
class Solution {
public:
      bool Palindrome(string s) {
          for (int  i = 0 ,k = s.size() - 1; i < s.size() / 2; i++,k--) {
              if(s[i] != s[k]) return false;
          }
          return true;
      }
      
      char Ttans(char str) { /*确定旋转后的*/
          switch (str)
          {
              case '>': return 'v';
              case 'v': return '<';
              case '^': return '>';
              case '<': return '^';
          }
          return '.';
      }
      
      void slove() {
        int n;
        while (cin >> n) {  
          // 二进制转换为字符串
            string s = bitset<32>(n).to_string(); // 将整数 n 转换为 32 位二进制字符串
            s.erase(0, s.find_first_not_of('0'));  //保留S第一个不为0的数
            cout << s << endl;
        }
      }
}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    cout.tie(0) -> ios::sync_with_stdio(0);
    #if Run
        int _;cin>>_;while(_--) slove();
    #else
        slove();
    #endif
    return 0;
}


//涉及知识点: 字符串 二进制数字转换为字符串
