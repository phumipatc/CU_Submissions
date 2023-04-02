/*
	Task	: ex06e2_shortest
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 April 2023 [14:35]
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
const int N = 110;
int dis[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,s;
	cin >> n >> m >> s;
	rep(i,0,n-1)
		rep(j,0,n-1)
			dis[i][j] = 1e9;
	dis[s][s] = 0;
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v],w);
	}
	rep(k,0,n-1)
		rep(i,0,n-1)
			rep(j,0,n-1)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	vector<int > ans;
	rep(i,0,n-1)
		ans.push_back((dis[s][i] == 1e9?-1:dis[s][i]));
	rep(k,0,n-1)
		rep(i,0,n-1)
			rep(j,0,n-1)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	vector<int > check;
	rep(i,0,n-1)
		check.push_back((dis[s][i] == 1e9?-1:dis[s][i]));
	if(ans != check)	cout << "-1\n";
	else{
		for(auto x:ans)
			cout << x << ' ';
		cout << '\n';
	}
	return 0;
}