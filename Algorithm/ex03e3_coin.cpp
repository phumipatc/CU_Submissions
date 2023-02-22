/*
	Task	: ex03e3_coin
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 February 2023 [22:18]
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
const int M = 1e4+10;
int dp[M];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	rep(i,1,m)
		dp[i] = 1e9;
	rep(i,1,n){
		int coin;
		cin >> coin;
		rep(j,coin,m)
			dp[j] = min(dp[j],dp[j-coin]+1);
	}
	cout << dp[m] << '\n';
	return 0;
}