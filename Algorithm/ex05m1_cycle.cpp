/*
	Task	: ex05m1_cycle
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 March 2023 [09:30]
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
const int N = 1010;
vector<int > g[N];
int deg[N];
bool mark[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q;
	cin >> q;
	while(q--){
		int n,e;
		cin >> n >> e;
		rep(i,1,e){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			deg[u]++,deg[v]++;
		}
		queue<int > que;
		rep(i,0,n-1)
			if(deg[i] <= 1)
				que.push(i),mark[i] = true;
		while(!que.empty()){
			int now = que.front();
			que.pop();
			for(auto x:g[now]){
				if(mark[x])	continue;
				deg[x]--;
				if(deg[x] <= 1)
					que.push(x),mark[x] = true;
			}
		}
		int ans = 1;
		rep(i,0,n-1)
			ans &= mark[i],mark[i] = false,deg[i] = 0,g[i].clear();
		if(ans)	cout << "NO\n";
		else	cout << "YES\n";
	}
	return 0;
}