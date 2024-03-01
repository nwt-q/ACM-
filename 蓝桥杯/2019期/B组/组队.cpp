#include<bits/stdc++.h>
using namespace std;
int team[20][6];
int vis[20];
int max_sum = 0;
void dfs(int index, int sum){
	if(index == 6){
		max_sum = max(max_sum, sum);
		return;
	}
	for(int i = 0; i < 20; i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(index + 1, sum + team[i][index]);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("team.txt", "r", stdin); //读team.txt文件 ,输入重定向 
        //注意把team.txt放到同一级目录下，或者把这行注释掉，手动输入 
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 6; j++)
			cin>>team[i][j];
	dfs(1, 0);
	cout<<max_sum<<endl;
	return 0;
}
