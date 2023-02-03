/*
	Task	: a64_q1_permu_before
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 19 January 2023 [09:51]
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > needBefore[22];
vector<int > now;
bool mark[22];
int n;
void permute(int state){
	if(state == n+1){
		for(auto x:now)
			cout << x << ' ';
		cout << '\n';
		return ;
	}
	// for(auto x:now)
	// 	cout << x << ' ';
	// cout << '\n';
	for(int i=0;i<n;i++){
		if(mark[i])	continue;
		bool ok = true;
		for(auto x:needBefore[i]){
			if(!mark[x]){
				ok = false;
				break;
			}
		}
		if(!ok)	continue;
		mark[i] = true;
		now.push_back(i);
		permute(state+1);
		now.pop_back();
		mark[i] = false;
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int k;
	cin >> n >> k;
	for(int i=1;i<=k;i++){
		int x,y;
		cin >> x >> y;
		needBefore[y].push_back(x);
	}
	permute(1);
	return 0;
}