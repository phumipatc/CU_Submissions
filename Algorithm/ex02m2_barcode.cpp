/*
	Task	: ex02m2_barcode
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 February 2023 [22:20]
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
const int N = 32;
int dp[N][N][N][2];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,x;
	cin >> n >> m >> x;
	dp[1][1][0][0] = 1;
	rep(i,2,n){
		// consider ith line
		rep(k,0,x){
			// had shift k times
			if(k > 0){
				rep(l,1,m){
					// special case: shifting to different color
					// (current line must be 1st consec. line)
					dp[i][1][k][0] += dp[i-1][l][k-1][1];
					dp[i][1][k][1] += dp[i-1][l][k-1][0];
				}
			}
			rep(j,2,m){
				// current line is jth consecutive line
				// ends with 0 (black)
				dp[i][j][k][0] = dp[i-1][j-1][k][0];
				dp[i][j][k][1] = dp[i-1][j-1][k][1];
			}
		}
	}
	int ans = 0;
	rep(j,1,m)
		ans += dp[n][j][x][0] + dp[n][j][x][1];
	cout << ans << '\n';
	return 0;
}