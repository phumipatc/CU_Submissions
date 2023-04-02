/*
	Task	: ex05e3_catapult
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 27 March 2023 [10:09]
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
stack<int > st;
int low[N],idx[N],onStack[N],comp[N],cnt[N];
int id,comp_num;
void dfs(int u,int p){
	low[u] = idx[u] = ++id;
	onStack[u] = 1;
	st.push(u);
	for(auto x:g[u]){
		if(!idx[x])			dfs(x,u),low[u] = min(low[u],low[x]);
		else if(onStack[x])	low[u] = min(low[u],idx[x]);
	}
	if(low[u] == idx[u]){
		++comp_num;
		while(!comp[u]){
			comp[st.top()] = comp_num;
			onStack[st.top()] = 0;
			st.pop();
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	rep(i,1,n){
		int num;
		cin >> num;
		while(num--){
			int v;
			cin >> v;
			v++;
			g[i].push_back(v);
		}
	}
	rep(i,1,n){
		if(idx[i])	continue;
		dfs(i,-1);
	}
	rep(i,1,n)
		cnt[comp[i]]++;
	sort(cnt+1,cnt+comp_num+1);
	rep(i,1,comp_num)
		cout << cnt[i] << ' ';
	return 0;
}