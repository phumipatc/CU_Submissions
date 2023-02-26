/*
	Task	: a64_q2_two_mcs
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 February 2023 [23:52]
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
const int N = 5e5+10;
int l[N],r[N],a[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,sum = 0;
	cin >> n;
	l[0] = -1e9;
	rep(i,1,n){
		cin >> a[i];
		sum+=a[i];
		l[i] = max(l[i-1],sum);
		sum = max(0,sum);
	}
	r[n+1] = -1e9,sum = 0;
	repr(i,n,1){
		sum+=a[i];
		r[i] = max(r[i+1],sum);
		sum = max(0,sum);
	}
	int mx = -1e9;
	l[0] = 0,r[n+1] = 0;
	rep(i,0,n)
		mx = max(mx,l[i] + r[i+1]);
	cout << mx << '\n';
	return 0;
}