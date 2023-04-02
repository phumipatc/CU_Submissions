/*
	Task	: ex06e3_columbia
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 April 2023 [14:50]
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
	int i,j,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int r,c;
	cin >> r >> c;
	vector<vector<int > > a(r),dis(r);
	vector<int > temp(c);
	rep(i,0,r-1){
		a[i] = dis[i] = temp;
		rep(j,0,c-1)
			cin >> a[i][j],dis[i][j] = 1e9;
	}
	priority_queue<A > heap;
	heap.push({0,0,0});
	dis[0][0] = 0;
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		rep(k,0,3){
			int ni = now.i + dir4[0][k];
			int nj = now.j + dir4[1][k];
			if(ni < 0 || nj < 0 || ni >= r || nj >= c)	continue;
			if(dis[ni][nj] <= now.w + a[ni][nj])		continue;
			dis[ni][nj] = now.w + a[ni][nj];
			heap.push({ni,nj,dis[ni][nj]});
		}
	}
	rep(i,0,r-1){
		rep(j,0,c-1)
			cout << dis[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}