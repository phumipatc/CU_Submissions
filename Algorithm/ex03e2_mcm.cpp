/*
	Task	: ex03e2_mcm
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 February 2023 [23:23]
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
const int N = 1e2+10;
int dp[N][N];
PII matrix[N];
int MCM(int l,int r){
	if(l == r)		return 0;
	if(dp[l][r])	return dp[l][r];
	dp[l][r] = 1e9;
	rep(k,l,r-1)
		dp[l][r] = min(dp[l][r],MCM(l,k) + MCM(k+1,r) + matrix[l].first*matrix[k].second*matrix[r].second);
	return dp[l][r];
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	rep(i,1,n){
		cin >> matrix[i].first;
		if(i != 1)
			matrix[i-1].second = matrix[i].first;
	}
	cin >> matrix[n].second;
	cout << MCM(1,n);
	return 0;
}