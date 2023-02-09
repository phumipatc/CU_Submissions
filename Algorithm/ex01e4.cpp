/*
	Task	: ex01e4
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 03 February 2023 [22:45]
*/
#include<bits/stdc++.h>
using namespace std;
int modN(int x,int n,int k){
	if(n == 0)	return 1;
	if(n == 1)	return x%k;
	int half = modN(x,n/2,k);
	if(n&1)	return (((half * half) % k) * x) % k;
	else	return (half * half)%k;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int x,n,k;
	cin >> x >> n >> k;
	cout << modN(x,n,k) << '\n';
	return 0;
}