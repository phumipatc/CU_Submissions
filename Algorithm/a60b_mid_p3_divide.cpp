/*
	Task	: a60b_mid_p3_divide
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 February 2023 [19:35]
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
#define MOD 1997
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
	int n,k;
	cin >> n >> k;
	dp[0][0] = 1;
	rep(i,1,n)
		rep(j,1,k)
			dp[i][j] = dp[i-1][j-1] + j * dp[i-1][j],dp[i][j] %= MOD;
	cout << dp[n][k] << '\n';
	return 0;
}