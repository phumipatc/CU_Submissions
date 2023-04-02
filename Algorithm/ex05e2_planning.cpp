/*
	Task	: ex05e2_planning
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 April 2023 [09:16]
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
int deg[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	rep(i,0,n-1){
		int m;
		cin >> m;
		deg[i] = m;
		while(m--){
			int v;
			cin >> v;
			g[v].push_back(i);
		}
	}
	queue<int > que;
	rep(i,0,n-1){
		if(deg[i])	continue;
		que.push(i);
	}
	while(!que.empty()){
		int now = que.front();
		que.pop();
		cout << now << ' ';
		for(auto x:g[now]){
			deg[x]--;
			if(deg[x])	continue;
			que.push(x);
		}
	}
	return 0;
}