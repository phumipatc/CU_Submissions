/*
	Task	: ex07e3_coloring
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 29 April 2023 [19:20]
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
const int N = 55;
bool edge[N][N];
int col[N];
int n,ans = 1e9;
bool valid(int v){
	rep(i,0,n-1)
		if(edge[v][i] && col[v] == col[i])
			return false;
	return true;
}
void paint(int now=0){
	if(now == n){
		int mx = 0;
		rep(i,0,n-1)
			mx = max(mx,col[i]);
		ans = min(ans,mx);
		return ;
	}
	rep(i,1,n){
		if(i > ans)	return ;
		col[now] = i;
		if(valid(now))
			paint(now+1);
		col[now] = 0;
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int e;
	cin >> n >> e;
	rep(i,1,e){
		int u,v;
		cin >> u >> v;
		edge[u][v] = edge[v][u] = true;
	}
	paint();
	cout << ans << '\n';
	return 0;
}