/*
	Task	: d62_q2c_wasted_space
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 September 2022 [21:25]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	cout << (1<<((int )ceil(log2(n)))) - n << '\n';
	return 0;
}