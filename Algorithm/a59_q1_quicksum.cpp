/*
	Task	: a59_q1_quicksum
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 February 2023 [23:20]
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
const int N = 1e3+10;
int qs[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,1,n)
		rep(j,1,m)
			cin >> qs[i][j],qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
	while(k--){
		int r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1++,c1++,r2++,c2++;
		cout << qs[r2][c2] - qs[r1-1][c2] - qs[r2][c1-1] + qs[r1-1][c1-1] << '\n';
	}
	return 0;
}