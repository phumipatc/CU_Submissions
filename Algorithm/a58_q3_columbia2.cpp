/*
	Task	: a58_q3_columbia2
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 02 April 2023 [21:18]
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
struct A{
	int v,w,state;
	bool operator < (const A&o) const{
		return w>o.w;
	};
};
int r,c;
vector<PII > g[200010];
int calc(int i,int j){
	return i*r + c;
}
PII decalc(int num){
	return {num/r,num%r};
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	cin >> r >> c;
	rep(i,0,r-1){
		rep(j,0,c-1){
			int num;
			cin >> num;
			rep(k,0,3){
				int ni = i + dir4[0][k];
				int nj = j + dir4[1][k];
				if(ni < 0 || ni >= r || nj < 0 || nj >= c)	continue;
				g[calc(ni,nj)].push_back({calc(i,j),num});
			}
		}
	}
	vector<vector<int > > dis(r*c,vector<int >(3,1e9));
	dis[0][0] = 0;
	priority_queue<A > heap;
	heap.push({0,0,0});
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		if(now.state < 2){
			for(auto x:g[now.v]){
				if(dis[x.first][now.state+1] > now.w){
					dis[x.first][now.state+1] = now.w;
					heap.push({x.first,now.w,now.state+1});
				}
				for(auto y:g[x.first]){
					if(dis[y.first][now.state+1] > now.w){
						dis[y.first][now.state+1] = now.w;
						heap.push({y.first,now.w,now.state+1});
					}
				}
			}
		}
		for(auto x:g[now.v]){
			if(dis[x.first][now.state] > now.w + x.second){
				dis[x.second][now.state] = now.w + x.second;
				heap.push({x.second,now.w + x.second,now.state});
			}
		}
	}
	rep(i,0,r-1){
		rep(j,0,c-1){
			cout << min({dis[calc(i,j)][0],dis[calc(i,j)][1],dis[calc(i,j)][2]}) << ' ';
		}
		cout << '\n';
	}
	return 0;
}