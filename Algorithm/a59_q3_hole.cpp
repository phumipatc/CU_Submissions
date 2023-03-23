/*
	Task	: a59_q3_hole
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 March 2023 [11:20]
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
struct A{
	int i,j,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
int dis[N][N],cost[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,x,y;
	cin >> n >> y >> x;
	rep(i,1,n){
		int u,v;
		cin >> u >> v;
		cost[v][u] = 1;
	}
	rep(i,0,1001)
		rep(j,0,1001)
			dis[i][j] = 1e9;
	priority_queue<A > que;
	que.push({x,y});
	dis[x][y] = 0;
	while(!que.empty()){
		A now = que.top();
		que.pop();
		if(now.i == 0 || now.i == 1001 || now.j == 0 || now.j == 1001){
			cout << now.w << '\n';
			return 0;
		}
		rep(k,0,3){
			int ni = now.i + dir4[0][k];
			int nj = now.j + dir4[1][k];
			if(ni < 0 || nj < 0 || ni > 1001 || nj > 1001)	continue;
			if(dis[ni][nj] != 1e9)							continue;
			dis[ni][nj] = now.w + cost[ni][nj];
			que.push({ni,nj,dis[ni][nj]});
		}
	}
	return 0;
}