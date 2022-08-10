/*
    Task	: ex00e2_Min_Max
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 10 August 2022 [10:15]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    int r1,r2,c1,c2;
    while(q--){
        cin >> r1 >> c1 >> r2 >> c2;
        if(r1 > r2 || c1 > c2){
            cout << "INVALID\n";
            continue;
        }
        if(r1 > n || r2 < 1 || c1 > m || c2 < 1){
            cout << "OUTSIDE\n";
            continue;
        }
        int mx = -1e9;
        for(int i=max(0,r1);i<=min(n,r2);i++)
            for(int j=max(0,c1);j<=min(m,c2);j++)
                mx = max(mx,a[i][j]);
        cout << mx << '\n';                
    }
    return 0;
}