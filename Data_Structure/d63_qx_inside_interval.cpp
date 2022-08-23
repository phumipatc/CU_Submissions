/*
	Task	: d63_qx_inside_interval
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 August 2022 [22:39]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,num;
	cin >> n >> m;
	vector<int > v(2*n);
	for(int i=0;i<n;i++){
		cin >> v[i] >> v[i+n];
		v[i+n]++;
	}
	sort(v.begin(),v.end());
	while(m--){
		cin >> num;
		int idx = upper_bound(v.begin(),v.end(),num) - v.begin();
		cout << (idx&1) << ' ';
	}
	return 0;
}