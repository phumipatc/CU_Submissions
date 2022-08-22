/*
	Task	: ex00e3
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 22 August 2022 [10:06]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,num;
	cin >> n;
	set<int > sett;
	for(int i=1;i<=n;i++){
		cin >> num;
		sett.insert(num);
	}
	if(*sett.begin() != 1 || *(--sett.end()) != n){
		cout << "NO\n";
		return 0;
	}
	if(sett.size() != n){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	return 0;
}