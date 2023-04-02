/*
	Task	: a60b_q3_ikea
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 April 2023 [09:26]
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
vector<int > g[N];
vector<int > deg,deg2;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	deg.resize(n+1,0);
	while(m--){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		deg[v]++;
	}
	int q = 5;
	while(q--){
		deg2 = deg;
		bool success = true;
		rep(i,1,n){
			int v;
			cin >> v;
			if(!success)	continue;
			if(deg2[v] != 0)
				success = false;
			for(auto x:g[v])
				deg2[x]--;
		}
		cout << (success?"SUCCESS":"FAIL") << '\n';
	}
	return 0;
}