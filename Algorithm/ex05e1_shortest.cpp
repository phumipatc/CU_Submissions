/*
	Task	: ex05e1_shortest
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 March 2023 [09:37]
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
const int N = 110;
char a[N][N];
int dis[N][N];
queue<PII > que;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int r,c;
	cin >> r >> c;
	rep(i,1,r)
		cin >> a[i]+1;
	rep(i,1,r)
		rep(j,1,c)
			dis[i][j] = 1e9;
	que.push({1,1});
	dis[1][1] = 0;
	while(!que.empty()){
		PII now = que.front();
		que.pop();
		if(now.first == r && now.second == c){
			cout << dis[r][c] << '\n';
			return 0;
		}
		rep(k,0,3){
			int ni = now.first + dir4[0][k];
			int nj = now.second + dir4[1][k];
			if(ni < 1 || nj < 1 || ni > r || nj > c)	continue;
			if(a[ni][nj] == '#')						continue;
			if(dis[ni][nj] != 1e9)						continue;
			dis[ni][nj] = dis[now.first][now.second]+1;
			que.push({ni,nj});
		}
	}
	cout << "-1\n";
	return 0;
}