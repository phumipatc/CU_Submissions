/*
	Task	: ex03e1_lcs
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 February 2023 [09:34]
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
char a[N],b[N];
int dp[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> a+1 >> b+1;
	int n = strlen(a+1),m = strlen(b+1);
	rep(i,1,n){
		rep(j,1,m){
			if(a[i] == b[j])	dp[i][j] = dp[i-1][j-1]+1;
			dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i][j-1]});
		}
	}
	cout << dp[n][m] << '\n';
	return 0;
}