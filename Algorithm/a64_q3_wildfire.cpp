/*
	Task	: a64_q3_wildfire
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 April 2023 [14:21]
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define repl(i, a, b) for(LL i = a; i <= (b); ++i)
#define reprl(i, a, b) for(LL i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) sort(all(x)),(x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int N = 5010;
int beauty[N],st[N];
vector<int > g[N];
int sum = 0;
void dfs(int u){
	if(beauty[u] == 0)	return ;
	sum-=beauty[u];
	beauty[u] = 0;
	for(auto x:g[u])
		dfs(x);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,0,n-1)
		cin >> beauty[i],sum+=beauty[i];
	rep(i,1,k)
		cin >> st[i];
	while(m--){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	rep(i,1,k){
		dfs(st[i]);
		cout << sum << ' ';
	}
	return 0;
}