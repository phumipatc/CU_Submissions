/*
	Task	: a60_q1_number1
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 11 February 2023 [16:53]
	Algo	: 
	Status	: 
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
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int divide(int l,int r,int num,int ll,int rr){
	if(r < ll || l > rr)	return 0;
	if(l == r)				return (num == 1);
	int mid = (l+r-1)/2;
	return divide(l,mid,num/2,ll,rr) + divide(mid+1,mid+1,num%2,ll,rr) + divide(mid+2,r,num/2,ll,rr);
}
void init(){
	
}
void solve(){
	int startNumber,l,r;
	cin >> startNumber >> l >> r;
	int n = 1;
	while(n < startNumber)	n = (2*n) + 1;
	cout << divide(1,n,startNumber,l,r) << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}