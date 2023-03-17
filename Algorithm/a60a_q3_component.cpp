/*
	Task	: a60a_q3_component
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 March 2023 [09:54]
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
const int N = 10010;
vector<int > g[N];
bool mark[N];
void dfs(int u){
	mark[u] = true;
	for(auto x:g[u]){
		if(mark[x])	continue;
		dfs(x);
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	rep(i,1,m){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int cnt = 0;
	rep(i,1,n){
		if(mark[i])	continue;
		cnt++;
		dfs(i);
	}
	cout << cnt << '\n';
	return 0;
}