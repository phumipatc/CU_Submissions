/*
	Task	: ex01e3
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 January 2023 [10:13]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	vector<int > a(n);
	for(auto &x:a)
		cin >> x;
	while(m--){
		int num;
		cin >> num;
		if(num < a[0]){
			cout << "-1\n";
			continue;
		}
		int l=0,r=n-1;
		while(l<r){
			int mid = (l+r+1)/2;
			if(a[mid] <= num)	l = mid;
			else				r = mid-1;
		}
		cout << a[l] << '\n';
	}
	return 0;
}