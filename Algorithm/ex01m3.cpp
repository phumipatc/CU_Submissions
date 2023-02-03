/*
	Task	: ex01m3
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 January 2023 [10:04]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,q;
	cin >> n >> q;
	vector<int > a(n);
	for(auto &x:a)
		cin >> x;
	while(q--){
		long long num;
		cin >> num;
		long long l=0,r = 1e15;
		while(l<r){
			long long mid = (l+r)/2,cnt = 0;
			for(auto x:a)
				cnt+=mid/x+1;
			if(cnt>=num)	r = mid;
			else			l = mid+1;
		}
		cout << l << '\n';
	}
	return 0;
}