/*
	Task	: a64_q4_path_sum
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 29 April 2023 [19:44]
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
int K[10];
int target;
vector<PII > g[25];
bool able,mark[25];
void walk(int now,int sum=0){
	if(sum == target){
		able = true;
		return ;
	}
	for(auto x:g[now]){
		if(mark[x.first])			continue;
		if(sum+x.second > target)	continue;
		mark[x.first] = true;
		walk(x.first,sum+x.second);
		mark[x.first] = false;
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int n,m;
	cin >> n >> m;
	rep(i,1,8)
		cin >> K[i];
	rep(i,1,m){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	rep(i,1,8){
		able = false;
		target = K[i];
		rep(j,0,n-1){
			mark[j] = true;
			walk(j);
			mark[j] = false;
		}
		cout << (able?"YES\n":"NO\n");
	}
	return 0;
}