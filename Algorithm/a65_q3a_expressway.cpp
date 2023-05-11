#include<bits/stdc++.h>
using namespace std;
const int N = 710;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
priority_queue<A > heap;
vector<A > g[N];
int dis[N];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    for(int i=1;i<N;i++)
        dis[i]=1e9;
    int w;
    cin >> n >> w;
    g[1].push_back({2,w});
    g[2].push_back({1,w});
    for(int i=3;i<=n;i++){
        int num;
        cin >> num;
        while(num--){
            int v,w;
            cin >> v >> w;
            g[i].push_back({v,w});
            g[v].push_back({i,w});
        }
        for(int j=1;j<=n;j++)
            dis[j] = 1e9;
        dis[1] = 0;
        heap.push({1,0});
        while(!heap.empty()){
            A now = heap.top();
            heap.pop();
            if(now.v == 2){
                cout << now.w << ' ';
                while(!heap.empty())    heap.pop();
                break;
            }
            for(auto x:g[now.v]){
                if(dis[x.v] <= now.w + x.w) continue;
                    dis[x.v] = now.w + x.w;
                    heap.push({x.v,dis[x.v]});
            }
        }
    }
    return 0;
}