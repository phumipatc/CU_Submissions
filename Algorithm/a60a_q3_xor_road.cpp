/*
	Task	: a60a_q3_xor_road
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 27 March 2023 [09:47]
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
const int N = 2010;
struct A{
	int u,v,w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
int a[N],p[N];
int fr(int u){
	if(p[u] == u)	return u;
	else			return p[u] = fr(p[u]);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	iota(p,p+n+1,0);
	rep(i,1,n)
		cin >> a[i];
	priority_queue<A > heap;
	rep(i,1,n)
		rep(j,i+1,n)
			heap.push({i,j,a[i]^a[j]});
	unsigned long long ans = 0;
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		int ru = fr(now.u);
		int rv = fr(now.v);
		if(ru == rv)	continue;
		p[ru] = rv;
		ans+=now.w;
	}
	cout << ans << '\n';
	return 0;
}