#include<stdio.h>      
#include<stdlib.h>      
#define N 100000005    
#define ll long long   
ll a[N + 5];     
int max(int x, int y) { return x > y ? x : y; }      
    
int ltm(ll x, ll n, ll m) {    
    long long sum = 0;  
    for (int i = 1; i <= n; i++) {  
        if (a[i] > x) {  
            sum += a[i] - x; // 只累加长度超过x的木材  
        }  
    }  
    return sum >= m; // 直接返回比较结果  
}    
    
int main()      
{   ll r = 0, l = 0, mid, n, m;  // 初始化r为0  
    scanf("%lld%lld", &n, &m);       
    for (int i = 1; i <= n; i++) {      
        scanf("%lld", &a[i]);      
        r = max(r, a[i]); // 找到最长木材  
    }     
    while (l < r) {    
        mid = (l + r + 1) / 2;    
        if (ltm(mid, n, m)) {  
            l = mid;    
        } else {  
            r = mid - 1;    
        }  
    } // 二分锯片高度  
    printf("%lld\n", l);    
    return 0;      
}

// https://www.educoder.net/classrooms/ospyjqb4/shixun_homework/1397445/detail?tabs=0
