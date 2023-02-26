/*
	Task	: a63_q1b_2side
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 February 2023 [23:19]
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
const int N = 2e5+10;
int a[N][2],dp[N][2],dp2[N][2][55];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,w,k;
	cin >> n >> w >> k;
	rep(i,1,n)
		cin >> a[i][0];
	rep(i,1,n)
		cin >> a[i][1];
	if(k == n){
		rep(i,1,n){
			// left at i
			dp[i][0] = dp[max(0,i-w-1)][1] + a[i][0];
			dp[i][0] = max(dp[i-1][0],dp[i][0]);
			// right at i
			dp[i][1] = dp[max(0,i-w-1)][0] + a[i][1];
			dp[i][1] = max(dp[i-1][1],dp[i][1]);
		}
		cout << max(dp[n][0],dp[n][1]) << '\n';
	}else{
		int mx = 0;
		rep(i,1,n){
			rep(j,1,k){
				// left at i
				dp2[i][0][j] = dp2[max(0,i-w-1)][1][j-1] + a[i][0];
				dp2[i][0][j] = max(dp2[i-1][0][j],dp2[i][0][j]);
				mx = max(mx,dp2[i][0][j]);
				// right at i
				dp2[i][1][j] = dp2[max(0,i-w-1)][0][j-1] + a[i][1];
				dp2[i][1][j] = max(dp2[i-1][1][j],dp2[i][1][j]);
				mx = max(mx,dp2[i][1][j]);
			}
		}
		cout << mx << '\n';
	}
	return 0;
}