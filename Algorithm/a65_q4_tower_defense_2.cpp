#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=b;--i)
#define all(x) begin(x),end(x)
#define decp(x) fixed << setprecision(x)
#define rmdup(x) sort(all(x)),(x).resize(unique((x).begin(),(x).end())-(x).begin())
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long , long long >;
struct A{
    int pos,v;
    bool operator < (const A&o) const{
        if(pos!=o.pos)  return pos < o.pos;
        else            return v < o.v;
    }
};
vector<A > a;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k,w,sum = 0;
    cin >> n >> m >> k >> w;
    a.resize(m);
    for(auto &x:a)
        cin >> x.pos;
    for(auto &x:a)
        cin >> x.v,sum+=x.v;
    sort(all(a));
    int lastUsed = 0;
    for(auto x:a){
        if(k == 0)  break;
        int now = max(0,x.pos-w);
        now = max(now,lastUsed+1);
        if(now == n+1)  break;
        int require = min(min({n,x.pos+w,now+x.v-1})-now+1,k);
        sum-=require;
        k-=require;
        lastUsed = min(x.pos+w,now+x.v-1);
//        cerr << x.pos << ' ' << x.v << ' ' << now << ' ' << lastUsed << '\n';
    }
    cout << sum << '\n';
    return 0;
}