/*
	Task	: ex00e4
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 19 January 2023 [10:36]
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > now;
int n,m;
void gen(int state){
	// state == length of now
	if(state == m){
		int cnt = 0;
		for(auto x:now)
			cnt+=x;
		if(cnt == n){
			for(auto x:now)
				cout << x;
			cout << '\n';
		}
		return ;
	}
	now.push_back(0);
	gen(state+1);
	now.pop_back();
	
	now.push_back(1);
	gen(state+1);
	now.pop_back();
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m;
	gen(0);
	return 0;
}