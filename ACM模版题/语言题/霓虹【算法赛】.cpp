#include <iostream>
using namespace std;
using ll = long long;

void solve(string s,string t) {
    int a[7][10] = {{1,0,1,1,0,1,1,1,1,1},{1,1,1,1,1,0,0,1,1,1},{1,1,0,1,1,1,1,1,1,1},{1,0,1,1,0,1,1,0,1,1},{1,0,1,0,0,0,1,0,1,0},{1,0,0,0,1,1,1,0,1,1},{0,0,1,1,1,1,1,0,1,1}};
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] != t[i]) {
          for (int j = 0; j < 7; j++) {
            if (a[j][s[i] - '0'] != a[j][t[i] - '0']) ans++;
          }
        }
    }
    std::cout << ans << endl;
}


int main()
{
  string s,T;
  std::cin >> s >> T;
  solve(s,T);
  return 0;
}

//https://www.lanqiao.cn/contests/newbie-7/challenges/
