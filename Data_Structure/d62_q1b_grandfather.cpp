/*
    Task	: d62_q1b_grandfather
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 19 August 2022 [10:37]
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > p(2000010,-1);
int findGrandfather(int u){
    if(p[u] == -1)	return -1;
    return p[p[u]];
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,m,cnt = 1;
    string a,b;
    map<string ,int > mapp;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        if(!mapp[a])    mapp[a] = cnt++;
        if(!mapp[b])    mapp[b] = cnt++;
        p[mapp[b]] = mapp[a];
    }
    while(m--){
        cin >> a >> b;
        if(!mapp[a] || !mapp[b] || mapp[a] == mapp[b]){
            cout << "NO\n";
            continue;
        }
        int pa = findGrandfather(mapp[a]),pb = findGrandfather(mapp[b]);
        if(pa == -1 || pb == -1 || pa!=pb)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}