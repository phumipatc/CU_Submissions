/*
	Task	: a60a_midp2_avl_distance
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 12 February 2023 [20:11]
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int > g[N];
int dp[50010][30];
int k;
int ans = 0;
void countDistanceK(int u){
	printf("u = %d\n",u);
	//using no child
	dp[u][0]++;
	//using 1 child
	for(auto x:g[u]){
		countDistanceK(x);
		for(int i=1;i<=25;i++)
			dp[u][i]+=dp[x][i-1];
		ans+=dp[x][k];
	}
	//using 2 child
	if(g[u].size() == 2){
		int l = g[u][0],r = g[u][1];
		for(int i=1;i<=25;i++)
			ans+=g[l][i]*g[r][k-i];
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n >> k;
	if(k>25){
		cout << "0\n";
		return 0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	countDistanceK(1);
	cout << ans << '\n';
	return 0;
}