/*
	Task	: ex06e1_cable
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 02 April 2023 [12:25]
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
const int N = 1010;
int a[N][N],dis[N],id[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	rep(i,1,n-1){
		id[i] = i;
		dis[i] = 1e9;
		rep(j,i+1,n)
			cin >> a[i][j];
	}
	id[n] = n,dis[n] = 1e9;
	dis[1] = 0;
	rep(i,1,n-1){
		int minn = 1e9,idx = 0;
		rep(j,i+1,n){
			dis[j] = min(dis[j],a[min(id[i],id[j])][max(id[i],id[j])]);
			if(dis[j] < minn){
				minn = dis[j];
				idx = j;
			}
		}
		swap(dis[i+1],dis[idx]);
		swap(id[i+1],id[idx]);
	}
	int sum = 0;
	rep(i,1,n)
		sum+=dis[i];
	cout << sum << '\n';
	return 0;
}