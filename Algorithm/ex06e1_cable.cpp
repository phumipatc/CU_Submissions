/*
	Task	: ex06e1_cable
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 April 2023 [09:33]
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
struct A{
	int u,v,w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
int p[N];
vector<A > edges;
int fr(int u){
	if(u == p[u])	return u;
	else			return p[u] = fr(p[u]);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	edges.resize(n-1);
	for(auto &x:edges)
		cin >> x.u >> x.v >> x.w;
	sort(all(edges));
	iota(p,p+n+1,0);
	int ans = 0;
	for(auto x:edges){
		int ru = fr(x.u);
		int rv = fr(x.v);
		if(ru == rv)	continue;
		p[ru] = rv;
		ans+=x.w;
	}
	cout << ans << '\n';
	return 0;
}