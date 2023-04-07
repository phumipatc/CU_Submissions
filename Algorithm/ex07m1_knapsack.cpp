/*
	Task	: ex07m1_knapsack
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 04 April 2023 [19:06]
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
const int N = 110;
double v[N],w[N];
map<double ,double > mapp,mapp2;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	double mx;
	int n;
	cin >> mx >> n;
	rep(i,1,n)
		cin >> v[i];
	rep(i,1,n)
		cin >> w[i];
	double ans = 0;
	mapp[0] = 0;
	rep(i,1,n){
		mapp2.clear();
		for(auto x:mapp){
			if(x.first + w[i] > mx)	continue;
			mapp2[x.first + w[i]] = max(mapp[x.first + w[i]],x.second + v[i]);
			ans = max(ans,x.second + v[i]);
		}
		for(auto x:mapp2)
			mapp[x.first] = x.second;
	}
	cout << decp(4) << ans << '\n';
	return 0;
}