/*
	Task	: ex01m1_restaurant
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 08 September 2022 [19:42]
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int t,id;
	bool operator < (const A&o) const{
		if(t!=o.t)	return t>o.t;
		else		return id>o.id;
	}
};
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	priority_queue<A > heap;
	vector<int > v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
		heap.push({0,i});
	}
	while(m--){
		cout << heap.top().t << '\n';
		auto now = heap.top();
		heap.pop();
		heap.push({now.t+v[now.id],now.id});
	}
	return 0;
}