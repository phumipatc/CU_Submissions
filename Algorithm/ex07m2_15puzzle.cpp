/*
	Task	: ex07m2_15puzzle
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 08 April 2023 [17:36]
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
	vector<vector<int > > a;
	int hi,hj,w;
	bool operator < (const A&o) const{
		return w > o.w;
	}
};
map<vector<vector<int > >  ,int > mapp;
PII correctPosition(int n){
	n--;
	return {n/4,n%4};
}
int distance(PII a,PII b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int forwardCost(vector<vector<int > > a){
	int sum = 0;
	rep(i,0,3){
		rep(j,0,3){
			if(a[i][j] == 0)	continue;
			sum+=distance({i,j},correctPosition(a[i][j]));
		}
	}
	return sum;
}
int findDist(vector<vector<int > > a){
	int hi,hj;
	auto finish = a;
	rep(i,0,3){
		rep(j,0,3){
			finish[i][j] = 4*i + j + 1;
			if(i == 3 && j == 3)
				finish[i][j] = 0;
			if(a[i][j] == 0)	hi = i,hj = j;
		}
	}
	priority_queue<A > heap;
	heap.push({a,hi,hj,forwardCost(a)});
	mapp[a] = 0;
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		now.w = mapp[now.a];
		// cerr << now.w << '\n';
		if(now.a == finish)
			return now.w;
		rep(k,0,3){
			int ni = now.hi + dir4[0][k];
			int nj = now.hj + dir4[1][k];
			if(ni < 0 || nj < 0 || ni > 3 || nj > 3)	continue;
			swap(now.a[now.hi][now.hj],now.a[ni][nj]);
			if(mapp.count(now.a) == 0){
				heap.push({now.a,ni,nj,now.w + 1 + forwardCost(now.a)});
				mapp[now.a] = now.w + 1;
			}
			swap(now.a[now.hi][now.hj],now.a[ni][nj]);
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	vector<vector<int > > a(4,vector<int >(4,0));
	for(auto &x:a)
		for(auto &y:x)
			cin >> y;
	cout << findDist(a) << '\n';
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 11 0 13 14 15 12
*/