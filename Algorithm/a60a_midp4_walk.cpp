/*
	Task	: a60a_midp4_walk
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 February 2023 [19:41]
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
const int N = 510;
int dp[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	rep(i,0,n)
		dp[i][0] = -1e9;
	rep(j,1,m)
		dp[0][j] = -1e9;
	rep(i,1,n){
		rep(j,1,m){
			int num;
			cin >> num;
			dp[i][j] = max({0,dp[i-1][j],dp[i][j-1],dp[i-1][j-1] + num}) + num;
		}
	}
	cout << dp[n][m] << '\n';
	return 0;
}