/*
	Task	: ex04e3_teamwork
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 29 April 2023 [12:08]
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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	int n,m;
	cin >> n >> m;
	vector<int > t(m);
	for(auto &x:t)
		cin >> x;
	sort(all(t));
	int now = 0;
	double all = 0;
	vector<int > sum(n,0);
	for(auto x:t){
		sum[now]+=x;
		all+=sum[now];
		now++,now%=n;
	}
	cout << decp(3) << (double )all/m << '\n';	
	return 0;
}