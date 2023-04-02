/*
	Task	: a62_q2a_line_graph
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 April 2023 [08:56]
	Algo	: 
	Status	: 
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
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 100010;
int deg[N];
bool mark[N];
vector<int > g[N];
void dfs2(int u){
	mark[u] = true;
	for(auto x:g[u]){
		if(mark[x])	continue;
		dfs2(x);
	}
}
int dfs(int u,int p){
	deg[u]--;
	mark[u] = true;
	// cerr << "DFS: " << u << ' ' << deg[u] << '\n';
	if(deg[u] > 1){
		dfs2(u);
		return 0;
	}
	for(auto x:g[u]){
		if(x == p)	continue;
		if(!dfs(x,u))
			return 0;
	}
	return 1;
}
void init(){
	
}
void solve(){
	int n,m;
	cin >> n >> m;
	while(m--){
		int u,v;
		cin >> u >> v;
		deg[u]++,deg[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int cnt = 0;
	rep(i,0,n-1){
		if(deg[i] > 1)	continue;
		if(mark[i])		continue;
		cnt+=dfs(i,-1);
		// cerr << "CNT: " << i << ' ' << cnt << '\n';
	}
	cout << cnt << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}