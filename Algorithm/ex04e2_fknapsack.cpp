/*
	Task	: ex04e2_fknapsack
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 30 April 2023 [08:15]
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
struct A{
	double v,w;
	bool operator < (const A&o) const{
		return (v/w) > (o.v/o.w);
	}
};
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/CU/input.in","r",stdin);
	double w;
	int n;
	cin >> w >> n;
	vector<A > items(n);
	for(auto &x:items)
		cin >> x.v;
	for(auto &x:items)
		cin >> x.w;
	sort(all(items));
	double currentWeight = 0,currentValue = 0;
	for(auto x:items){
		if(currentWeight + x.w <= w){
			currentWeight+=x.w;
			currentValue+=x.v;
		}else{
			currentValue+=x.v*(w-currentWeight)/x.w;
			currentWeight = w;
			break;
		}
	}
	cout << decp(4) << currentValue << '\n';
	return 0;
}