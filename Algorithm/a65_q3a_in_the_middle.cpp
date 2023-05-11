#include<bits/stdc++.h>
using namespace std;
const int N = 250010;
vector<int > g[N];
int st[3];
int dis[3][N];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n >> st[0] >> st[1] >> st[2];
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        while(num--){
            int num2;
            cin >> num2;
            g[i].push_back(num2);
        }
    }
    queue<int > que;
    for(int k=0;k<3;k++){
        for(int i=1;i<=n;i++)
            dis[k][i] = 1e9;
        dis[k][st[k]] = 0;
        que.push(st[k]);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(auto x:g[now]){
                if(dis[k][x] <= dis[k][now] + 1)  continue;
                dis[k][x] = dis[k][now] + 1;
                que.push(x);
            }
        }
    }
    int ans = 1e9;
    for(int i=1;i<=n;i++){
        int minn = -1e9;
        for(int k=0;k<3;k++){
            minn = max(minn,dis[k][i]);
        }
        ans = min(ans,minn);
    }
    cout << ans << '\n';
    return 0;
}