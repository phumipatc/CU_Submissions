/*
	Task	: a60a_midp1_knapsack
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 February 2023 [23:28]
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
const int N = 5e3+10;
int value[N],weight[N];
int dp[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	rep(i,1,n)
		cin >> value[i];
	rep(i,1,n)
		cin >> weight[i];
	rep(i,0,n)
		rep(j,0,m)
			cin >> dp[i][j];
	int i = n,j = m;
	vector<int > selectedItem;
	while(i > 0 && j > 0){
		// printf("%d %d\n",i,j);
		if(dp[i][j] == dp[i-1][j]){
			i--;
		}else if(j>=weight[i] && dp[i][j] == dp[i-1][j-weight[i]] + value[i]){
			selectedItem.push_back(i);
			j-=weight[i--];
		}
	}
	cout << selectedItem.size() << '\n';
	for(auto x:selectedItem)
		cout << x << ' ';
	cout << '\n';
	return 0;
}