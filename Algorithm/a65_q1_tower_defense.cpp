#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,v;
    bool operator < (const A&o) const{
        return idx<o.idx;
    }
};
A a[10];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    for(int i=1;i<=m;i++){
        cin >> a[i].idx;
    }
    for(int i=1;i<=m;i++)
        cin >> a[i].v;
    sort(a+1,a+m+1);
    int now = 1;
    vector<int > pos(k);
    for(auto &x:pos)
        cin >> x;
    sort(pos.begin(),pos.end());
    for(auto x:pos){
        while(now <= m && a[now].idx < x-w) now++;
        if(a[now].idx > x+w)    continue;
        if(now > m) break;
        a[now].v--;
    }
    int ans = 0;
    for(int i=1;i<=m;i++)
        ans+=a[i].v;
    cout << ans << '\n';
    return 0;
}