/*
	Task	: ex02e2_cnk
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 09 February 2023 [11:36]
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 32;
int dp[N][N];
int Binomial(int n,int k){
	if(k == 0 || k == n)	return 1;
	if(dp[n][k] != 0)		return dp[n][k];
	return dp[n][k] = Binomial(n-1,k-1) + Binomial(n-1,k);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,k;
	cin >> n >> k;
	cout << Binomial(n,k) << '\n';
	return 0;
}