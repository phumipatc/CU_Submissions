/*
	Task	: a59_midp1_lcs
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 February 2023 [23:41]
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
int dp[N][N];
char a[N],b[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m >> a+1 >> b+1;	
	rep(i,0,n)
		rep(j,0,m)
			cin >> dp[i][j];
	int i = n,j = m;
	vector<char > commonWord;
	while(i > 0 && j > 0){
		if(a[i] == b[j]){
			commonWord.push_back(a[i]);
			i--,j--;
		}else if(dp[i][j] == dp[i-1][j])
			i--;
		else
			j--;
	}
	reverse(all(commonWord));
	for(auto x:commonWord)
		cout << x;
	cout << '\n';
	return 0;
}