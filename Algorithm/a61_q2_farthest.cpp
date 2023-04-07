/*
	Task	: a61_q2_farthest
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 02 April 2023 [20:52]
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
int dis[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int n;
	cin >> n;
	rep(i,1,n){
		rep(j,1,n){
			cin >> dis[i][j];
			if(dis[i][j] == -1)	dis[i][j] = 1e9;
		}
	}
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	int ans = -1;
	rep(i,2,n){
		if(dis[1][i] == 1e9){
			cout << "-1\n";
			return 0;
		}
		ans = max(ans,dis[1][i]);
	}
	cout << ans << '\n';
	return 0;
}