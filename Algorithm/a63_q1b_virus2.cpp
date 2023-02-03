/*
	Task	: a63_q1b_virus2
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 19 January 2023 [10:10]
*/
#include<bits/stdc++.h>
using namespace std;
int a[33000];
int divide(int l,int r){
	if(l == r)	return a[l];
	int mid = (l+r)/2;
	int resL = divide(l,mid);
	int resR = divide(mid+1,r);
	if(resL == -1 || resR == -1 || abs(resL-resR) > 1)
		return -1;
	return resL+resR;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q,k;
	cin >> q >> k;
	int n = 1<<k;
	while(q--){
		for(int i=1;i<=n;i++)
			cin >> a[i];
		cout << (divide(1,n) != -1?"yes\n":"no\n");
	}
	return 0;
}