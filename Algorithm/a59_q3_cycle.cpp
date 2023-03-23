/*
	Task	: a59_q3_cycle
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 20 March 2023 [11:21]
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
int deg[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	rep(i,1,n){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	queue<int > que;
	rep(i,0,n-1){
		// printf("%d %d\n",i,deg[i]);
		if(deg[i] > 1)	continue;
		que.push(i);
	}
	while(!que.empty()){
		int now = que.front();
		que.pop();
		deg[now]--;
		// printf("%d\n",now);
		for(auto x:g[now]){
			deg[x]--;
			if(deg[x] == 1)	que.push(x);
		}
	}
	int cnt = 0;
	rep(i,0,n-1)
		cnt+=(deg[i] > 0);
	cout << cnt << '\n';
	return 0;
}