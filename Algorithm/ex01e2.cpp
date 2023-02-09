/*
	Task	: ex01e2
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 03 February 2023 [22:41]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	long long sum=0,mx=-1e18,mn=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		int num;
		cin >> num;
		sum+=num;
		mx = max(mx,sum-mn);
		mn = min(mn,sum);
	}
	cout << mx << '\n';
	return 0;
}