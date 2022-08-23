/*
	Task	: d63_q1b_interval_count
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 August 2022 [22:51]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,k,num;
	cin >> n >> m >> k;
	vector<int > v(n);
	for(auto &x:v)
		cin >> x;
	sort(v.begin(),v.end());
	while(m--){
		cin >> num;
		auto l = lower_bound(v.begin(),v.end(),num-k);
		auto r = upper_bound(v.begin(),v.end(),num+k);
		cout << (r-l) << ' ';
	}
	return 0;
}