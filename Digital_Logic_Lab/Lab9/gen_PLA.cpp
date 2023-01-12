/*
	Task	: gen_PLA
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 November 2022 [22:00]
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
void init(){
	
}
//input order are
// reset P20 P10 P5 Pcoffee Ptea Pchange Pnext s3 s2 s1 s0 b5 b4 b3 b2 b1 b0 c20-1 c20-0 c10 c5
map<vector<int >,int > b0n,b1n,b2n,b3n,b4n,b5n,s0n,s1n,s2n,s3n,c5n,c10n,c200n,c201n;
vector<int > intToBin(int n){
	vector<int > res;
	while(n > 0){
		res.push_back(n%2);
		n/=2;
	}
	while(res.size()!=6)
		res.push_back(0);
	reverse(all(res));
	return res;
}
int binToInt(vector<int > n){
	int sum = 0;
	while(!n.empty()){
		sum*=2;
		sum+=n.back();
		n.pop_back();
	}
	return sum;
}
void balance0(){
	
}
void solve(){
	auto f = freopen("balance0.txt","w",stdout);
	balance0();
	fclose(f);
	auto f = freopen("balance1.txt","w",stdout);
	balance1();
	fclose(f);
	// balance2();
	// balance3();
	// balance4();
	// balance5();
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