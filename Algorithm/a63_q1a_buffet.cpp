/*
	Task	: a63_q1a_buffet
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 February 2023 [23:05]
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
int a[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,k,m;
	cin >> n >> k >> m;
	rep(i,1,n)
		cin >> a[i],a[i]+=a[i-1] - m;
	while(k--){
		int p,w;
		cin >> p >> w;
		int idx = lower_bound(a+p,a+n+1,a[p-1]+w)-a;
		cout << idx << '\n';
	}
	return 0;
}