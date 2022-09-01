/*
	Task	: d64_q1b_moving_median
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 September 2022 [17:59]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,w,num;
	cin >> n >> w;
	vector<int > a(n+1);
	multiset<int > low,high;
	for(int i=1;i<=w;i++){
		cin >> a[i];
		low.insert(a[i]);
	}
	while(low.size() > high.size()+1){
		high.insert(*(--low.end()));
		low.erase((--low.end()));
	}
	for(int i=w+1;i<=n;i++){
		cin >> a[i];
		low.insert(a[i]);
		if(*(--low.end()) > *high.begin()){
			high.insert(*(--low.end()));
			low.erase((--low.end()));
			if(high.size() > low.size()){
				low.insert(*high.begin());
				high.erase(high.begin());
			}
		}
		num = *(--low.end());
		cout << num << ' ';
		if(a[i-w] <= num){
			low.erase(low.lower_bound(a[i-w]));
		}else{
			high.erase(high.lower_bound(a[i-w]));
			high.insert(*(--low.end()));
			low.erase(--low.end());
		}
	}
	return 0;
}