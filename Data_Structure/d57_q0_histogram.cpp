/*
	Task	: d57_q0_histogram
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 24 August 2022 [11:37]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	string str;
	map<string ,int > mapp;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> str;
		mapp[str]++;
	}
	for(auto x:mapp){
		if(x.second == 1)	continue;
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}