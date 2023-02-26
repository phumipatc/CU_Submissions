/*
	Task	: a64_q2_table_no_11
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 February 2023 [23:42]
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
#define MOD (LL )(1e8+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
int dp[2][3];
// 0 is 00, 1 is 01, 2 is 10
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	dp[0][0] = 1;
	int idx = 1;
	rep(i,1,n){
		dp[idx][0] = (dp[!idx][0] + dp[!idx][1] + dp[!idx][2])%MOD;
		dp[idx][1] = (dp[!idx][0] + dp[!idx][2]) % MOD;
		dp[idx][2] = (dp[!idx][0] + dp[!idx][1]) % MOD;
		idx = !idx;
	}
	cout << (dp[n&1][0] + dp[n&1][1] + dp[n&1][2]) % MOD << '\n';
	return 0;
}