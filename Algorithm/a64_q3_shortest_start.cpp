/*
	Task	: a64_q3_shortest_start
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 April 2023 [14:05]
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
struct A{
	int v,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
int dis[N];
bool st[N];
vector<PII > g[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,k,en;
	cin >> n >> m >> k >> en;
	fill(dis,dis+n,1e9);
	rep(i,1,k){
		int v;
		cin >> v;
		st[v] = true;
	}
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		g[v].push_back({u,w});
	}
	dis[en] = 0;
	priority_queue<A > heap;
	heap.push({en,0});
	int ans = 1e9;
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		// cerr << now.v << ' ' << now.w << '\n';
		if(st[now.v])
			ans = min(ans,dis[now.v]);
		for(auto x:g[now.v]){
			if(dis[x.first] <= dis[now.v] + x.second)	continue;
			dis[x.first] = dis[now.v] + x.second;
			heap.push({x.first,dis[x.first]});
		}
	}
	cout << ans << '\n';
	return 0;
}