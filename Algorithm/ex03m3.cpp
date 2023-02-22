/*
	Task	: ex03m3
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 February 2023 [23:48]
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
const int N = 1e5+10;
int dp[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,k;
	cin >> n >> k;
	rep(i,1,n){
		int cost;
		cin >> cost;
		int mn = 1e9;
		rep(j,max(0,i-k-1),i-1)
			mn = min(mn,dp[j]);
		rep(j,max(1,i-2*k-1),i-k-2)
			mn = min(mn,dp[j]);
		dp[i] = mn + cost;
		// printf("%d: %d\n",i,dp[i]);
	}
	int mn = 1e9;
	rep(i,max(1,n-k),n)
		mn = min(mn,dp[i]);
	cout << mn << '\n';
	return 0;
}