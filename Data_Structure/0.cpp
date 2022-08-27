/*
	Task	: 0
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 24 August 2022 [12:18]
*/
#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > s;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	s.insert({1,1});
	for(auto x:s)
		cout << x.first << " " << x.second << "\n"; 
	return 0;
}