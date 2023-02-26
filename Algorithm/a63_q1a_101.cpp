/*
	Task	: a63_q1a_101
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 February 2023 [22:01]
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
#define MOD (LL )(1e8+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
// const int N = 10010;
// int dp[N][2];
// int main(){
// 	cin.tie(0)->sync_with_stdio(0);
// 	cin.exceptions(cin.failbit);
// 	int n;
// 	cin >> n;
// 	dp[1][0] = dp[1][1] = 1;
// 	dp[0][0] = dp[0][1] = 1;
// 	rep(i,2,n){
// 		dp[i][0]+=dp[i-1][0] + dp[i-1][1];
// 		dp[i][0]%=MOD;
// 		// dp[i][1]+=dp[i-1][1] + (dp[i-1][0] - dp[i-2][1] + MOD)%MOD;
// 		dp[i][1]+=dp[i-1][1] + dp[i-2][0];
// 		dp[i][1]%=MOD;
// 	}
// 	cout << (dp[n][0] + dp[n][1])%MOD << '\n';
// 	return 0;
// }
struct A{
	long long a[7][7];

	A operator * (const A&o) const{
		A temp;
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				temp.a[i][j] = 0;
				for(int k=0;k<7;k++){
					temp.a[i][j] += (a[i][k] * o.a[k][j]) % MOD;
					temp.a[i][j]%=MOD;
				}
			}
		}
		return temp;
	}
};
A p[42],now;
int main(){
	p[0] = {1,1,0,0,0,0,0,
			0,1,1,0,0,0,0,
			1,0,0,0,0,0,0,
			0,1,0,0,0,0,0,
			0,0,1,0,0,0,0,
			0,0,0,1,0,0,0,
			0,0,0,0,0,0,1};
	rep(i,1,40)
		p[i] = p[i-1]*p[i-1];
	long long n;
	cin >> n;
	now.a[0][0] = 2;
	now.a[1][0] = 2;
	now.a[2][0] = 1;
	now.a[3][0] = 1;
	now.a[4][0] = 1;
	now.a[5][0] = 1;
	now.a[6][0] = MOD;
	n-=2;
	rep(i,0,40){
		if(n & (1ll << i)){
			now = p[i] * now;
		}
	}
	cout << (now.a[0][0] + now.a[1][0])%MOD << '\n';
}