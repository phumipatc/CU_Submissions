/*
	Task	: ex07e3_coloring
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 12 April 2023 [20:36]
*/
#include<iostream>
#include<vector>
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
vector<int > g[N];
int c[N];
int n,ans = N;
bool valid(int now,int col){
	for(auto x:g[now]){
		if(c[x] == col)	return false;
	}
	return true;
}
void paint(int now){
	if(now == n){
		int cnt = 1;
		rep(i,0,n-1)
			cnt = max(cnt,c[i]);
		ans = min(ans,cnt);
		return ;
	}
	int mx = 0;
	for(auto x:g[now])
		mx = max(mx,c[x]);
	vector<bool > forbid(mx+1,false);
	for(auto x:g[now])
		forbid[c[x]] = true;
	rep(i,1,n){
		if(i > ans)	break;
		if(forbid[i])	continue;
		c[now] = i;
		paint(now+1);
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int m;
	cin >> n >> m;
	rep(i,1,m){
		int u,v;
		cin >> u >> v;
		g[max(u,v)].push_back(min(u,v));
	}
	paint(0);
	cout << ans << '\n';
	return 0;
}