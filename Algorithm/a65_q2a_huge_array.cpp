#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
pair<int ,int > a[N];
int b[N];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
        cin >> a[i].first >> a[i].second;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i] = b[i-1] + a[i].second;
    while(q--){
        int idx;
        cin >> idx;
        int ans = lower_bound(b+1,b+n+1,idx)-b;
        cout << a[ans].first << '\n';
    }
    return 0;
}