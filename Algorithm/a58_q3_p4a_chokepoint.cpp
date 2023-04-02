/*
	Task	: a58_q3_p4a_chokepoint
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 27 March 2023 [11:03]
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
const int N = 100010;
vector<int > g[N];
int subtree[N];
LL dp[N];
int n;
void dfs(int u,int p){
	subtree[u]++;
	LL sum = 0;
	for(auto x:g[u]){
		if(x == p)	continue;
		dfs(x,u);
		sum+=subtree[x];
	}
	subtree[u]+=sum;
	// (u, parent)
	dp[u] += (n-sum-1);
	// (child, parent)
	dp[u] += (sum * (n-sum-1));
	for(auto x:g[u]){
		sum-=subtree[x];
		// (child1, child2)
		dp[u]+=subtree[x] * sum;
		// (u,child)
		dp[u]+=subtree[x];
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n;
	rep(i,1,n-1){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,0);
	rep(i,0,n-1)
		cout << dp[i] << '\n';
	return 0;
}