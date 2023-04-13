/*
	Task	: ex07e2_iss
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 12 April 2023 [22:25]
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
const int N = 110;
int v[N][N];	// want, start at least
int ans = 0;
int bruteforce(int n,int st){
	if(v[n][st] != -1)	return v[n][st];
	if(n == 0)			return v[n][st] = 1;
	if(st > n)			return v[n][st] = 0;
	int ret = 0;
	rep(i,st,n)
		ret+=bruteforce(n-i,i);
	return v[n][st] = ret;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int n;
	cin >> n;
	memset(v,-1,sizeof v);
	cout << bruteforce(n,1) << '\n';
	return 0;
}