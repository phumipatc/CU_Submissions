/*
	Task	: mid_p4_gaa
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 11 February 2023 [17:04]
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
char result(int l,int r,int target,int num){
	if(num == 0)					return (l == target)?'g':'a';
	// printf("%d %d %d %d\n",l,r,target,num);
	int leftEnd = l + (r-l+1-(num+3))/2 - 1;
	int rightStart = leftEnd + num + 3 + 1;
	if(target <= leftEnd)	return result(l,leftEnd,target,num-1);
	else if(target < rightStart){
		if(target == leftEnd+1)	return 'g';
		else					return 'a';
	}else	return result(rightStart,r,target,num-1);
}
void init(){
	
}
void solve(){
	int target;
	cin >> target;
	int n = 3,cnt = 0;
	while(n < target)	n = (2*n) + (++cnt) + 3;
	cout << result(1,n,target,cnt) << '\n';
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