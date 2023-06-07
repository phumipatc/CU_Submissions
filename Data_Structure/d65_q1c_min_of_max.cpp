#include<bits/stdc++.h>
using namespace std;
int p[500010];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    vector<int > v(50010);
    for(int i=0;i<=50000;i++)
        v[i] = 1;
    map<int ,int > mp;
    cin >> n >> m;
    mp[1] = m;
    for(int i=1;i<=n;i++)
        cin >> p[i];
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        if(p[i]>v[num]){
            mp[v[num]]--;
            if(mp[v[num]] == 0) mp.erase(v[num]);
            mp[p[i]]++;
            v[num] = p[i];
        }
        for(auto x:mp){
            cout << x.first << ' ';
            break;
        }
    }
}