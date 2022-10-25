/*
	Task	: d62_q3b_kheap_height
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 October 2022 [14:26]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	long long n,num = 1;
	int k,ans = -1;
	cin >> n >> k;
	if(k == 1)
		ans = n-1,n = 0;
	while(n>0){
		n-=num;
		num*=k;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}