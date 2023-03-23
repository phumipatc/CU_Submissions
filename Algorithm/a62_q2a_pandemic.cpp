/*
	Task	: a62_q2a_pandemic
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 20 March 2023 [11:07]
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
const int N = 510;
int a[N][N],dis[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int r,c,t;
	cin >> r >> c >> t;
	queue<PII > que;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin >> a[i][j];
			dis[i][j] = 1e9;
			if(a[i][j] == 1){
				que.push({i,j});
				dis[i][j] = 0;
			}
		}
	}
	int cnt = 0;
	while(!que.empty()){
		PII now = que.front();
		que.pop();
		cnt++;
		if(dis[now.first][now.second] == t)
			continue;
		for(int k=0;k<4;k++){
			int ni = now.first + dir4[0][k];
			int nj = now.second + dir4[1][k];
			if(ni < 1 || nj < 1 || ni > r || nj > c)	continue;
			if(a[ni][nj] == 2)							continue;
			if(dis[ni][nj] != 1e9)						continue;
			dis[ni][nj] = dis[now.first][now.second] + 1;
			que.push({ni,nj});
		}
	}
	cout << cnt << '\n';
	return 0;
}