/*
	Task	: a64_q4_closest_subset
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 12 April 2023 [23:15]
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
const int K = 100010;
map<int , map<int , bool > > dp;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int n,m,k;
	cin >> n >> m >> k;
	dp[0][0] = true;
	rep(i,1,n){
		int num;
		cin >> num;
		for(auto it = dp.rbegin();it != dp.rend();it++){
			auto x = *it;
			if(x.first == m)	continue;
			int last = 0;
			if(dp.count(x.first+1) && dp[x.first+1].size() > 0)	last = (*(--dp[x.first+1].end())).first;
			for(auto &y:x.second){
				if(last >= k && y.first + num >= last)	continue;
				dp[x.first+1][y.first + num] = true;
				// cerr << num << ' ' << x.first+1 << ' ' << y.first + num << '\n';
			}
		}
	}
	int ans = 1e9;
	for(auto x:dp[m])
		ans = min(ans,abs(x.first-k));
	cout << ans << '\n';
	return 0;
}