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
bool mark[85][1010],dp[85][1010];
int price[85];
int n,k,ans = 1e9;
bool haveAll(vector<bool > having){
    vector<bool > check(having.size(),true);
    return having == check;
}
void recurse(int now,vector<bool > having,int sum=0){
    if(sum > ans)   return ;
    bool correct = haveAll(having);
    if(now == k || correct){
        if(correct){
            ans = min(ans,sum);
        }
        return ;
    }
    vector<bool > checking = having;
//    cerr << "Just done buying " << now << '\n';
//    rep(i,1,n)
//        cerr << (having[i] == true) << ' ';
//    cerr << '\n';
    rep(i,1,n)
        checking[i] = checking[i] || dp[now+1][i];
//    cerr << "In future\n";
//    rep(i,1,n)
//        cerr << (checking[i] == true) << ' ';
//    cerr << (haveAll(checking) == true) << '\n';
    if(!haveAll(checking))  return ;
    int futureSum = 1e9;
    rep(i,now+1,k)
        futureSum = min(futureSum,price[i]);
    if(sum+futureSum > ans) return ;
    checking = having;
    rep(i,1,n)
        checking[i] = checking[i] || mark[now+1][i];
//    cerr << "buy " << now+1 << " at " << sum+price[now+1] << '\n';
    recurse(now+1,checking,sum+price[now+1]);
//    cerr << "not buy " << now+1 << " at " << sum << '\n';
    recurse(now+1,having,sum);
}
struct A{
    int p;
    vector<int > a;
    bool operator < (const A&o) const{
        if(p!=o.p)  return a.size() > o.a.size();
        else        return p<o.p;
    }
};
vector<A > a;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    a.resize(k);
    rep(i,1,k){
        int m,num;
        cin >> a[i-1].p >> m;
        while(m--){
            cin >> num;
            a[i-1].a.push_back(num);
        }
    }
    sort(all(a));
    rep(i,1,k){
        price[i] = a[i-1].p;
        for(auto x:a[i-1].a)
            mark[i][x] = true;
    }
    repr(i,k,1)
        rep(j,1,n)
            dp[i][j] = mark[i][j] || dp[i+1][j];
    vector<bool > having(n+1,false);
    having[0] = true;
    recurse(0,having);
    cout << ans << '\n';
    return 0;
}