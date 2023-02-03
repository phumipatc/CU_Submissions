/*
	Task	: ex02e3_bs
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 January 2023 [09:56]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	vector<pair<int ,int > >  a(n);
	for(int i=0;i<n;i++)
		cin >> a[i].first,a[i].second = i;
	for(int i=1;i<n;i++)
		a[i].second = max(a[i].second,a[i-1].second);
	while(m--){
		int num;
		cin >> num;
		if(a[0].first > num){
			cout << "-1\n";
			continue;
		}
		int l=0,r=n-1;
		while(l<r){
			int mid = (l+r+1)/2;
			if(a[mid].first <= num)	l = mid;
			else					r = mid-1;
		}
		cout << a[l].second << '\n';
	}
	return 0;
}