/*
	Task	: d62_q3a_heap_descendant
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 October 2022 [14:55]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	queue<int > que,ans;
	que.push(m);
	while(!que.empty()){
		int now = que.front();
		que.pop();
		ans.push(now);		
		if(now*2+1<n)	que.push(now*2+1);
		if(now*2+2<n)	que.push(now*2+2);
	}
	cout << ans.size() << '\n';
	while(!ans.empty())
		cout << ans.front() << ' ',ans.pop();
	return 0;
}