/*
	Task	: ex03h1_square
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 February 2023 [20:16]
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
int dp[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int r,c;
	cin >> r >> c;
	int ans = 0;
	rep(i,1,r){
		rep(j,1,c){
			char num;
			cin >> num;
			if(num == '1')	dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}