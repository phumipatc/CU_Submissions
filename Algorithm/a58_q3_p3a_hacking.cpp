/*
	Task	: a58_q3_p3a_hacking
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 27 March 2023 [10:32]
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
const int N = 50010;
struct A{
	int v,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
vector<int > g[N];
int dis[N],cost[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,0,n-1)
		dis[i] = 1e9;
	priority_queue<A > heap;
	rep(i,1,k){
		int v;
		cin >> v;
		dis[v] = 0;
	}
	rep(i,0,n-1){
		cin >> cost[i];
		if(dis[i] == 0)
			heap.push({i,cost[i]});
	}
	rep(i,1,m){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		ans = max(ans,dis[now.v]);
		// printf("%d %d\n",now.v,dis[now.v]);
		for(auto x:g[now.v]){
			if(dis[x] < now.w + cost[x])	continue;
			dis[x] = now.w + cost[x];
			heap.push({x,dis[x]});
		}
	}
	cout << ans << '\n';
	return 0;
}