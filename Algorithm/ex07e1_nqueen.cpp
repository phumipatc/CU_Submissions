/*
	Task	: ex07e1_nqueen
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 13 April 2023 [10:28]
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
const int N = 15;
int c[N];
bool mark[N];
int n,ans = 0;
bool valid(int i,int j){
	rep(k,1,i-1){
		if(i-k == abs(j-c[k]))	return false;
	}
	return true;
}
void recurse(int now){
	if(now == n+1){
		ans++;
		return ;
	}
	rep(i,1,n){
		if(mark[i])			continue;
		if(!valid(now,i))	continue;
		mark[i] = true;
		c[now] = i;
		recurse(now+1);
		mark[i] = false;
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	cin >> n;
	recurse(1);
	cout << ans << '\n';
	return 0;
}