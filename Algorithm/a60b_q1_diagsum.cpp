/*
	Task	: a60b_q1_diagsum
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 February 2023 [23:07]
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
const int N = 1e3+10;
int a[N][N];
PII dp[N][N];	// sum + min
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,ans = -1e9;
	cin >> n;
	rep(i,1,n){
		rep(j,1,n){
			int num;
			cin >> num;
			dp[i][j].first = num + dp[i-1][j-1].first;
			ans = max(ans,dp[i][j].first - dp[i-1][j-1].second);
			dp[i][j].second = min(dp[i][j].first,dp[i-1][j-1].second);
			// printf("%d %d: %d %d\n",i,j,dp[i][j].first,dp[i][j].second);
		}
	}
	cout << ans << '\n';

	return 0;
}