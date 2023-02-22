/*
	Task	: q59_q1_ones
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 11 February 2023 [19:20]
*/
#include<bits/stdc++.h>
using namespace std;
int recurse(int n,int digits){
	if(n < 11)	return min(n,11-n);
	
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	int smallestBigger = 11,digits = 2;
	while(smallestBigger<=n){
		smallestBigger = (smallestBigger * 10)+1;
		digits++;
	}
	cout << recurse(n,digits) << '\n';
	return 0;
}