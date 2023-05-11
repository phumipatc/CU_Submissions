#include<bits/stdc++.h>
#define MOD 100000007
using namespace std;
const int N = 5010;
int dp[N][2];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin >> n >> k;
    dp[0][1] = 1;
    for(int i=1;i<=n;i++){
        dp[i][0]+=dp[i-1][0] + dp[i-1][1];
        dp[i][0]%=MOD;
        for(int j=1;j<=i-k;j++){
            dp[i][1]+=dp[j][1];
            dp[i][1]%=MOD;
        }
        dp[i][1]++;
        dp[i][1]%=MOD;
//        printf("%d: %d %d\n",i,dp[i][0],dp[i][1]);
    }
    cout << (dp[n][0] + dp[n][1])%MOD << '\n';
    return 0;
}