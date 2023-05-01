/*
	Task	: ex04m2_salesman
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 29 April 2023 [12:54]
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
const int N = 10010,M = 1010;
int order[M];
LL qs[M];
int m;
LL findMinDist(int a,int b){
	if(a > b)	swap(a,b);
	// cerr << a << ' ' << b << ": " << qs[b]-qs[a] << ' ' << qs[a] + qs[m] - qs[b] << '\n';
	return min({qs[b]-qs[a],qs[a] + qs[m] - qs[b]});
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int n;
	cin >> n >> m;
	rep(i,1,m)
		cin >> order[i];
	order[m+1] = order[1];
	rep(i,1,m)
		cin >> qs[i],qs[i]+=qs[i-1];
	//qs[i] mean cost of distance from 0 to i
	rep(i,1,n){
		int a,b;
		cin >> a >> b;
		LL mn = 0;
		rep(j,2,m+1){
			// 3 cases
			// direct walk
			// a->b
			// b->a
			mn += min({findMinDist(order[j-1],order[j]), findMinDist(order[j-1],a) + findMinDist(b,order[j]), findMinDist(order[j-1],b) + findMinDist(a,order[j])});
			// cerr << findMinDist(order[j-1],order[j]) << ' ' << findMinDist(order[j-1],a) + findMinDist(b,order[j]) << ' ' << findMinDist(order[j-1],b) + findMinDist(a,order[j]) << '\n';
		}
		cout << mn << '\n';
	}
	return 0;
}