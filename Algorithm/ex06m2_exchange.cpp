/*
	Task	: ex06m2_exchange
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 02 April 2023 [21:01]
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
const int N = 510;
double rate[N][N],rate2[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		rep(i,1,n)
			rep(j,1,n)
				cin >> rate[i][j];
		rep(k,1,n)
			rep(i,1,n)
				rep(j,1,n)
					rate[i][j] = max(rate[i][j],rate[i][k] * rate[k][j]);
		bool yes = false;
		rep(i,1,n)
			if(rate[i][i] > 1)
				yes = true;
		cout << (yes?"YES":"NO") << '\n';
	}
	return 0;
}
/*
2
3
1 0.7 1.2
1.1 1 2
0.75 0.7 1
2
1 0.7
1.2 1
*/