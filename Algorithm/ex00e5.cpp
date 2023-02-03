/*
	Task	: ex00e5
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 19 January 2023 [10:45]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > now;
int n,m;
void gen(int state){
	// state == length of now
	if(state == m){
		int cnt = 0,mx = 0;
		for(auto x:now){
			cnt+=x;
			if(x == 0)	cnt = 0;
			mx = max(mx,cnt);
		}
		if(mx >= n){
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
	cin >> m >> n;
	gen(0);
	return 0;
}