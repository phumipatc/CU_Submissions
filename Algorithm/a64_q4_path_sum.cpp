/*
	Task	: a64_q4_path_sum
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 13 April 2023 [10:43]
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
const int N = 22;
vector<PII > g[N];
bool mark[N];
bool ans[20010];
int want[10];
vector<int > considering;
void dfs(int u,int d=0){
	if(considering.empty())		return ;
	ans[d] = true;
	if(ans[considering.back()]){
		while(!considering.empty() && ans[considering.back()])	considering.pop_back();
		return ;
	}
	if(d > considering.back())	return ;
	mark[u] = true;
	for(auto x:g[u]){
		if(mark[x.first])	continue;
		dfs(x.first,d+x.second);
	}
	mark[u] = false;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int n,m;
	cin >> n >> m;
	rep(i,1,8)
		cin >> want[i],considering.push_back(want[i]);
	sort(all(considering));
	rep(i,1,m){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	rep(i,0,n-1)
		dfs(i);
	rep(i,1,8)
		cout << (ans[want[i]]?"YES":"NO") << '\n';
	return 0;
}