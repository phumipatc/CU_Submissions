#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int dp[N][N],a[N];
int divide(int l,int r){
    if(l >= r)              return 0;
    if(dp[l][r] != -1e9)    return dp[l][r];
    int mx=0;
    for(int k=l;k<r;k++)
        mx = max(mx,divide(l,k) + divide(k+1,r));
    return dp[l][r] = max({a[l] * a[r] + divide(l+1,r-1),mx});
}
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = -1e9;
    cout << divide(1,n);
    return 0;
}