/*
	Task	: a62_q1b_chocolate
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 February 2023 [22:49]
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
#define MOD (LL )(1e6+3)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int N = 1e4+10;
const int K = 12;
int dp[N];
int num[K];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,k;
	cin >> n >> k;
	rep(i,1,k)
		cin >> num[i];
	dp[0] = 1;
	rep(i,1,n){
		rep(j,1,k){
			if(i < num[j])	continue;
			dp[i] += dp[i-num[j]];
			dp[i] %= MOD;
		}
	}
	cout << dp[n] << '\n';
	return 0;
}