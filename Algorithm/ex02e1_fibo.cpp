/*
	Task	: ex02e1_fibo
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 09 February 2023 [11:33]
*/
#include<bits/stdc++.h>
using namespace std;
int dp[50];
int fibo(int n){
	if(n == 0)		return 0;
	if(n == 1)		return 1;
	if(dp[n] != 0)	return dp[n];
	return dp[n] = fibo(n-1) + fibo(n-2);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	cout << fibo(n) << '\n';
	return 0;
}