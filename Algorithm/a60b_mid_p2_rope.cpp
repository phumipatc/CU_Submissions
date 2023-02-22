/*
	Task	: a60b_mid_p2_rope
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 February 2023 [19:38]
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
const int N = 4e3+10;
int dp[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	dp[0] = 0;
	rep(i,1,n){
		dp[i] = -1e9;
		if(i >= a)	dp[i] = max(dp[i],dp[i-a]+1);
		if(i >= b)	dp[i] = max(dp[i],dp[i-b]+1);
		if(i >= c)	dp[i] = max(dp[i],dp[i-c]+1);
	}
	cout << dp[n] << '\n';
	return 0;
}