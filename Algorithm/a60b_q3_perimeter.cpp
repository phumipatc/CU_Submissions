/*
	Task	: a60b_q3_perimeter
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 20 March 2023 [11:14]
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
int dis[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,e,k;
	cin >> n >> e >> k;
	rep(i,1,e){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int > que;
	rep(i,1,n)
		dis[i] = 1e9;
	que.push(0);
	int cnt = 0;
	while(!que.empty()){
		int now = que.front();
		que.pop();
		if(dis[now] == k){
			cnt++;
			continue;
		}
		for(auto x:g[now]){
			if(dis[x] != 1e9)	continue;
			dis[x] = dis[now]+1;
			que.push(x);
		}
	}
	cout << cnt << '\n';
	return 0;
}